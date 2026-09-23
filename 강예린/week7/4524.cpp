#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//reverse(): 배열의 순서를 뒤집는 함수
//compare(int x, int y) return x>y : 내림차순으로

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.begin() + n);
	reverse(arr.begin(), arr.begin() + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}