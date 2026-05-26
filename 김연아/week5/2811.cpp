#include <iostream>
using namespace std;
#include <vector>
#include <string> 
#include <algorithm> 
#include <cmath>
int isPrime(int n) {

    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) { //2의 배수, 3의배수... 제외해나가기
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int num[5];
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 5; i++) {
        if (num[i] == 1) cout << "number one\n";
        else {
            if (isPrime(num[i])) cout << "prime number\n";
            else cout << "composite number\n";
        }
    }
    return 0;
}