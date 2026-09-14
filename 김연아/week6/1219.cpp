#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;       // 행, 열
int paper_cnt;  // 사용 가능한 색종이 수
int N;          // 잘못 칠해진 칸의 수
vector<int> cols;
int max_row = 0;

// 색종이 크기가 L일 때, paper_cnt 장 이하로 모두 덮을 수 있는가?
bool check(int L) {
    int count = 0;
    int covered_until = 0; // 현재 색종이가 덮고 있는 마지막 열

    for (int col : cols) {
        // 아직 안 덮인 열이 나타나면 새로운 색종이를 붙임
        if (col > covered_until) {
            count++;
            covered_until = col + L - 1; // col부터 col+L-1 열까지 커버
        }
    }

    return count <= paper_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> R >> C)) return 0;
    cin >> paper_cnt;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        max_row = max(max_row, r); // 가장 높은 행 갱신
        cols.push_back(c);
    }

    // 열 번호 기준 오름차순 정렬
    sort(cols.begin(), cols.end());
    // 중복 열 제거 (같은 열에 여러 개 잘못 칠해져 있어도 가로는 하나로 취급)
    cols.erase(unique(cols.begin(), cols.end()), cols.end());

    // 이분 탐색
    int left = max(1, max_row); // 세로를 덮기 위해 최소 max_row 이상이어야 함
    int right = max(R, C);
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check(mid)) {
            ans = mid;         // 가능한 크기이므로 기록
            right = mid - 1;   // 더 작은 크기가 가능한지 왼쪽 탐색
        }
        else {
            left = mid + 1;    // 불가능하므로 크기를 키움
        }
    }

    cout << ans << "\n";

    return 0;
}