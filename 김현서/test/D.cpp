#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long cnt[100005];
long long dp[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        max_val = max(max_val, x);
    }

    dp[0] = 0;
    dp[1] = cnt[1] * 1;

    for (int i = 2; i <= max_val; i++) {
   
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }

    cout << dp[max_val] << "\n";
    return 0;
}