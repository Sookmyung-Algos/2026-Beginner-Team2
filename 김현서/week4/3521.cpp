#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, e, N;
    cin >> a >> b >> c >> d >> e >> N;

    int weight[5] = { 1, 2, 4, 8, 16 };
    int cnt[5] = { a, b, c, d, e };

    int dp[201];
    int INF = 999999;

    for (int i = 0; i <= 200; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            for (int k = 200; k >= weight[i]; k--) {
                if (dp[k - weight[i]] != INF) {
                    dp[k] = min(dp[k], dp[k - weight[i]] + 1);
                }
            }
        }
    }

    if (dp[N] == INF) {
        cout << "impossible";
    }
    else {
        cout << dp[N];
    }

    return 0;
}