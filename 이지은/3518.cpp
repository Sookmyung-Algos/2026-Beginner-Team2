#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<int> a;

void printArray() {
    for (int i = 0; i < (int)a.size(); ++i)
        cout << a[i] << (i + 1 == (int)a.size() ? '\n' : ' ');
}

int partitionArray(int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high;
    while (i <= j) {
        while (i <= j && a[i] <= pivot) ++i;
        while (i <= j && a[j] >= pivot) --j;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    printArray();
    return j;
}
void quickSort(int low, int high) {
    if (low >= high) return;
    int p = partitionArray(low, high);
    quickSort(low, p - 1);
    quickSort(p + 1, high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    a.resize(n);
    for (int& x : a) cin >> x;
    quickSort(0, n - 1);
    return 0;
}
