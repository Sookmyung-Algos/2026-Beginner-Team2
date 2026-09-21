#include <iostream>

using namespace std;

int arr[100005];
int Sum[100005]; 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        Sum[i] = Sum[i - 1] + arr[i]; 
    }

    
    int maxV = -100000000;

    for (int i = k; i <= n; i++) {
        int curSum = Sum[i] - Sum[i - k];
        if (curSum > maxV) {
            maxV = curSum;
        }
    }

    cout << maxV << "\n";

    return 0;
}