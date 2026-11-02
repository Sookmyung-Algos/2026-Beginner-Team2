#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> B[i];

    // dp[i][j] :
    // A의 i-1번 원소와 B의 j-1번 원소를
    // 마지막으로 선택한 상태에서 만들 수 있는 LIS의 최대 길이
    // i 또는 j가 0이면 해당 수열에서 아직 선택하지 않은 상태

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    int answer = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {

            int last = INT_MIN;

            if (i > 0)
                last = max(last, A[i - 1]);

            if (j > 0)
                last = max(last, B[j - 1]);

            // A에서 다음 원소 선택
            for (int k = i; k < N; k++) {
                if (A[k] > last) {
                    dp[k + 1][j] = max(
                        dp[k + 1][j],
                        dp[i][j] + 1
                    );
                }
            }

            // B에서 다음 원소 선택
            for (int k = j; k < M; k++) {
                if (B[k] > last) {
                    dp[i][k + 1] = max(
                        dp[i][k + 1],
                        dp[i][j] + 1
                    );
                }
            }

            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer << '\n';

    return 0;
}