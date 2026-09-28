#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    //base case
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    //n>1 case 
    vector<long long> f(n + 1);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD; // ¸Å µ¡¼À¸¶´Ù MOD ¿¬»ê ÇÊ¼ö
    }

    cout << f[n] << "\n";

    return 0;
}