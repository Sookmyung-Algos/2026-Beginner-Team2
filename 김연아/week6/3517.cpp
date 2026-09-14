#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end()); //오름차순 정렬

    int q;
    cin >> q;
    int req;
    int mid;
    int left, right;

    for (int i = 0; i < q; i++) {
        left = 0; right = n - 1;
        int answer = -1;
        cin >> req;
        while (left <= right) { //등호 필수
            mid = left + (right - left) / 2;
            if (req == v[mid]) {
                answer = mid;
                break;
            }
            else {
                if (req < v[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        cout << answer << ' ';
    }

}
