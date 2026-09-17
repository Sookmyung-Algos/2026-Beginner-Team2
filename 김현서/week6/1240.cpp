#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    if (!(cin >> N)) return 0;

    if (N == 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long low = 1;
    long long high = N;
    long long a = 1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid <= N / mid) {
            a = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << a << "\n";

    return 0;
}