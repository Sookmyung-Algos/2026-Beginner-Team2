
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string check_number(long long n) {
    if (n == 1) {
        return "number one";
    }
    
    long long limit = sqrt(n);
    for (long long i = 2; i <= limit; ++i) {
        if (n % i == 0) {
            return "composite number";
        }
    }
    return "prime number";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;

    for (int i = 0; i < 5; ++i) {
        if (cin >> n) {
            cout << check_number(n) << "\n";
        }
    }

    return 0;
}
