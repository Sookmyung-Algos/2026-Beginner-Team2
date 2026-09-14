#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int left = 1;
    long long right = n;
    int mid;
    int answer = 1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid * mid <= n) { //mid 는 정답후보
            answer = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << answer;
}
