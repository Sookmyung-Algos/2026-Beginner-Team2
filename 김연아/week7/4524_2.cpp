#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int& x, int& y) { //참조형 매개변수(직접 접근) 
    return x > y; //bool 리턴 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}