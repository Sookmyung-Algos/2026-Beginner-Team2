#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 1. 첫 K개 요소의 합 계산 (첫 번째 윈도우)
    long long current_sum = 0;
    for (int i = 0; i < K; i++) {
        current_sum += arr[i];
    }

    long long max_sum = current_sum;

    // 2. 슬라이딩 윈도우 적용
    for (int i = K; i < N; i++) {
        current_sum += arr[i] - arr[i - K]; // 새 원소 추가, 맨 앞 원소 제거
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";

    return 0;
}