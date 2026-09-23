#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>&arr, int low, int high) {
	if (low >= high) return;

	int pivot = arr[low];
	int i = low + 1;
	int j = high;
	while (i <= j) {
		while (i <= j && arr[i] <= pivot)
			i++;
		while (i <= j && pivot <= arr[j])
			j--;
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[j]); 

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';

	quickSort(arr, low, j - 1, n);
	quickSort(arr, j + 1, high, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);

	return 0;
}