#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const long long MOD = 1000000007LL;
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    cout << dp[n] << '\n';
    return 0;
}