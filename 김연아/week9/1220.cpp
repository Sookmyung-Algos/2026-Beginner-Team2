#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;

    cin >> A >> B;

    int n = A.length();
    int m = B.length();

    int dp[1001][1001] = { 0 };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}