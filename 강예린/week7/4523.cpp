#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//sort(): 오름차순 정렬 함수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n+1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int s, e;
	cin >> s >> e;

	sort(arr.begin() + s, arr.begin() + e + 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n";

	sort(arr.begin(), arr.begin() + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}