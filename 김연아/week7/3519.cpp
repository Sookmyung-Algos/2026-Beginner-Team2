#include <iostream>
#include <vector>

using namespace std;

// 배열 전체의 상태를 한 줄로 출력
void printArray(const vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << (i + 1 == (int)arr.size() ? "" : " ");
    }
    cout << "\n";
}

// 두 정렬된 부분 병합하는 함수
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    // 두 구간의 원소를 비교하여 작은 값부터 temp에 채움
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    // 왼쪽 구간에 남은 원소 처리
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // 오른쪽 구간에 남은 원소 처리
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    //temp에 정렬된 값들을 원본 배열 arr에 복사
    for (int t = 0; t < (int)temp.size(); t++) {
        arr[left + t] = temp[t];
    }

    printArray(arr);
}

// 합병 정렬 재귀 함수
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);        // 왼쪽 분할 정렬
        mergeSort(arr, mid + 1, right);   // 오른쪽 분할 정렬
        merge(arr, left, mid, right);     // 병합 및 출력
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    return 0;
}