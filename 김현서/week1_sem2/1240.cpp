#include <iostream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, a;
    cin >> N;
    long long low = 1;
    long long high = N;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (mid * mid <= N) {
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