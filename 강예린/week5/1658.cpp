#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    if (b == 0) return a;
    return getGCD(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    // 최대공약수 계산
    int gcd = getGCD(a, b);

    // 최소공배수 계산
    int lcm = (a / gcd) * b;

    // 결과 출력
    cout << gcd << "\n";
    cout << lcm << "\n";

    return 0;
}