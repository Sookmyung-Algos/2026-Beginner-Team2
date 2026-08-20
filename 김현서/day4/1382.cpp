#include <iostream>

using namespace std;

int coins[11];   
int dp[64001];      

int main() {
    int n, target;


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    cin >> target;

    
    for (int i = 1; i <= target; i++) {
        dp[i] = 999999;
    }
    dp[0] = 0;

   
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coins[j]) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    cout << dp[target] << endl;

    return 0;
}