#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	vector <int> sorted(arr.size());

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}

	while (i <= mid) {
		sorted[k++] = arr[i++];
	}

	while (j <= right) {
		sorted[k++] = arr[j++];
	}

	for (int idx = left; idx <= right; idx++) {
		arr[idx] = sorted[idx];
	}
}

void mergeSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);

		for (int idx = 0; idx < arr.size(); idx++) {
			cout << arr[idx] << ' ';
		}
		cout << '\n';
	}
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

	mergeSort(arr, 0, arr.size() - 1);

	return 0;
}