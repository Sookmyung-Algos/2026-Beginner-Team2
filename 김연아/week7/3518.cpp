#include <iostream>
#include <algorithm>

using namespace std;

int a[1005];
int n;

void quick_sort(int low, int high) {
    if (low >= high)
        return;

    // pivot은 구간의 가장 왼쪽 원소
    int pivot = a[low];

    int i = low + 1;
    int j = high;

    while (i <= j) {

        // pivot보다 큰 값 찾기
        while (i <= j && a[i] <= pivot)
            i++;

        // pivot보다 작은 값 찾기
        while (i <= j && a[j] >= pivot)
            j--;

        // 두 값을 교환
        if (i < j)
            swap(a[i], a[j]);
    }

    // pivot을 자기 자리로 이동
    swap(a[low], a[j]);

    // 분할 이후 배열 전체 출력
    for (int k = 0; k < n; k++)
        cout << a[k] << " ";
    cout << '\n';

    // pivot 기준 왼쪽 / 오른쪽 재귀 호출
    quick_sort(low, j - 1);
    quick_sort(j + 1, high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(0, n - 1);

    return 0;
}