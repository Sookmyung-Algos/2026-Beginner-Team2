#include <iostream>
using namespace std;

longl ling power(long long x, long long y) {
    if (y == 0) {
        return 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const long long M = 20091024;

    long long x, y;
    cin >> x >> y;
    cout << pow(x, y) % M << "\n";

    return 0;