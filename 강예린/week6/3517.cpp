#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int q;
	cin >> q;
	vector<int> b(q);
	for (int i = 0; i < q; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < q; i++) {
		int low = 0;
		int high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (a[mid] == b[i]){
				cout << mid << " ";
				break;
			}
			else if (a[mid] > b[i]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}

			if (low > high)cout << "-1" << " "; //찾는값이 없다면 -1 출력
		}
	}

	return 0;
}