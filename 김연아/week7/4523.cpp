#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int start, end;
    cin >> start >> end;

    sort(v.begin() + start, v.begin() + end + 1); //end 인덱스까지 정렬
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}