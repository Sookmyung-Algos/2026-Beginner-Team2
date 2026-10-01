#include <iostream>
using namespace std;
const long long MOD = 1000000007; //10억7

int main() {
    int N;
    cin >> N;

    long long dp[100001]; //피보나치 나머지 저장

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[N];

    return 0;
}