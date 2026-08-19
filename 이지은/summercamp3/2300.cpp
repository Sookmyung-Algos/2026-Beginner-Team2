#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

 
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = N - 1;

    long long min_diff = 2000000001; // 충분히 큰 값 설정
    long long ans1 = 0, ans2 = 0;

    // 2. 투 포인터 탐색 (O(N))
    while (left < right) {
        long long sum = arr[left] + arr[right];

        // 0과의 거리가 더 가까운 경우 갱신
        if (abs(sum) < min_diff) {
            min_diff = abs(sum);
            ans1 = arr[left];
            ans2 = arr[right];
        }

        // 합이 0보다 작으면 값을 키우기 위해 left 이동, 크면 줄이기 위해 right 이동
        if (sum < 0) {
            left++;
        }
        else if (sum > 0) {
            right--;
        }
        else {
            // 정확히 0이 되면 최적의 정답이므로 종료
            break;
        }
    }

    cout << ans1 << " " << ans2 << "\n";

    return 0;
}