#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;
    unsigned long long low = 1, high = n, answer = 0;
    while (low <= high) {
        unsigned long long mid = low + (high - low) / 2;
        if (mid <= n / mid) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << answer << '\n';
    return 0;
}