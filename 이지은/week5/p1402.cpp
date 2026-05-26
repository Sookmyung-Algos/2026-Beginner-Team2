
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            count++;
            if (count == k) {
                cout << i << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}
