#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    long long current_sum = 0;
    int max_books = 0;

    for (int right = 0; right < n; right++) {
        current_sum += a[right];

        while (current_sum > t) {
            current_sum -= a[left];
            left++;
        }

        max_books = max(max_books, right - left + 1);
    }

    cout << max_books << "\n";
    return 0;
}