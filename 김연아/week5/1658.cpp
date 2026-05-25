#include <iostream>
using namespace std;
#include <vector>
#include <string> 
#include <algorithm> 
#include <cmath>
int gcd(int a, int b) { //최대공약수 
    while (1) {
        if (b == 0) break;
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, k;
    cin >> n >> k;
    //최소공배수=두 수 곱하고 최대공약수로 나눈 수

    int answer = gcd(n, k);
    cout << answer << endl;
    cout << (n * k) / answer;

    return 0;
}