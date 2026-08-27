#include <iostream>

using namespace std;

int arr[100005];
long long preSum[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        preSum[i] = preSum[i - 1] + arr[i];
    }

    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;

        cout << preSum[e] - preSum[s - 1] << "\n";
    }

    return 0;
}