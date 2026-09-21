#include <iostream>
using namespace std;

const long long M = 20091024;

long long power(long long x, long long y) {
    if (y == 0) {
        return 1;
    }

    long long half = power(x, y / 2);
    long long result = (half * half) % M;

    if (y % 2 != 0) {
        result = (result * (x % M)) % M;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    if (cin >> x >> y) {
  
        cout << power(x, y) << "\n";
    }

    return 0;
}