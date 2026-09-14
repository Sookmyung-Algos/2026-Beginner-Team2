#include <iostream>
using namespace std;

int arr[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

    }
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == t) {
                ans = mid;
                high = mid - 1;
            }
            else if (arr[mid] < t) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        cout << ans << " ";
    }

    return 0;
}