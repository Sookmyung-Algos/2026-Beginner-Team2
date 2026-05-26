#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n;
	cin >> k;

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			count++;
			if (count == k) {
				cout << i;
				return 0;
			}
		}
	}

	if (count < k) {
		cout << 0;
	}

	return 0;
}