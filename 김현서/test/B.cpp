#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int step = 0;

    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        }
        else {
            m += 1;
        }
        step++;
    }

    step += (n - m);

    cout << step << "\n";
    return 0;
}