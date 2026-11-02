#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int n = A.length();
    int m = B.length();

    int dp[4001] = { 0 };
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {

            if (A[i - 1] == B[j - 1]) {
                dp[j] = dp[j - 1] + 1;
            }
            else {
                dp[j] = 0;
            }

            answer = max(answer, dp[j]);
        }
    }

    cout << answer << '\n';

    return 0;
}