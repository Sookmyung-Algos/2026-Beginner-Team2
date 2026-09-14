#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    long long n;
    cin >> n;

    long long low = 1;
    long long high = n;
    long long answer = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (mid <= n / mid) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << answer;

    return 0;
}