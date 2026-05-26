#include <iostream>
using namespace std;
#include <vector>
#include <string> 
#include <algorithm> 
#include <cmath>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, k;
    cin >> n >> k;


    vector <int> v;

    for (int i = 1; i <= sqrt(n); i++) {
        if (i == sqrt(n)) {
            v.push_back(i);
            break;
        }
        if (n % i == 0) {
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    /*
    for (int i = 0; i < v.size(); i++) {
        cout << v[i]<<endl;
    }
    */

    int answer;
    if (v.size() < n) answer = 0;
    answer = v[k - 1];
    cout << answer;


    return 0;
}