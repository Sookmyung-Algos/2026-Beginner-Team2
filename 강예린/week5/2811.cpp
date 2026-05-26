#include <iostream>
#include <vector>
using namespace std;

void checkNumber(long long n) {
    if (n == 1) {
        cout << "number one\n";
        return;
    }

    bool isPrime = true;

    // 제곱근까지만 탐색하여 시간 단축
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        cout << "prime number\n";
    }
    else {
        cout << "composite number\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
    vector<long long> numbers(5);


    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < 5; i++) {
        checkNumber(numbers[i]);
    }

    return 0;
}