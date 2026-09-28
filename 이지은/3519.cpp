#include <iostream>
#include <vector>
using namespace std;

vector<int> a, temp;

void printArray() {
    for (int i = 0; i < (int)a.size(); ++i)
        cout << a[i] << (i + 1 == (int)a.size() ? '\n' : ' ');
}
void mergeSort(int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (int p = left; p <= right; ++p) a[p] = temp[p];
    printArray();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    a.resize(n);
    temp.resize(n);
    for (int& x : a) cin >> x;
    mergeSort(0, n - 1);
    return 0;
}