#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, target;
    if (!(cin >> n)) return 0;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cin >> target;

    vector<int> dp(target + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i <= target; i++) {
            if (dp[i - coin] != INF) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[target] == INF) cout << -1 << "\n";
    else cout << dp[target] << "\n";

    return 0;
}