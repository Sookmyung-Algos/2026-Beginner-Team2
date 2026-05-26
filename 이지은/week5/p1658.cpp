
#include <iostream>

using namespace std;

long long get_gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (cin >> a >> b) {
        long long g = get_gcd(a, b);
        long long l = (a * b) / g; 
        
        cout << g << "\n";
        cout << l << "\n";
    }

    return 0;
}
