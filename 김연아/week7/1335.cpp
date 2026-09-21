#include <iostream>
#include <vector>

using namespace std;

int whiteCount = 0; // 하얀색 색종이(0) 개수
int blueCount = 0;  // 파란색 색종이(1) 개수
vector<vector<int>> paper; //여러 함수에서 공통으로 접근 (전역) 

// (r, c) 위치에서 시작하는 크기 size x size 영역 검사
void solve(int r, int c, int size) {
    int color = paper[r][c];
    bool isSame = true;

    // 현재 영역이 모두 같은 색인지 확인
    for (int i = r; i < r + size; i++) {
        for (int j = c; j < c + size; j++) {
            if (paper[i][j] != color) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    // 모두 같은 색이면 해당 색종이 카운트 증가
    if (isSame) {
        if (color == 0) whiteCount++;
        else blueCount++;
        return;
    }

    // 색이 섞여 있으면 4개의 사분면으로 쪼개서 재귀 호출
    int half = size / 2;
    solve(r, c, half);              // 1사분면 (좌상단)
    solve(r, c + half, half);       // 2사분면 (우상단)
    solve(r + half, c, half);       // 3사분면 (좌하단)
    solve(r + half, c + half, half); // 4사분면 (우하단)
}

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    paper.assign(n, vector<int>(n)); //2차원 벡터
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    // 전체 종이(0, 0) 크기 n에 대해 분할 정복 시작
    solve(0, 0, n);

    // 하얀색(0) 개수, 파란색(1) 개수를 줄바꿈하여 출력
    cout << whiteCount << "\n";
    cout << blueCount << "\n";

    return 0;
}