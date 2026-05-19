#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int price;
    cin >> price;

    int bill = price / 10000;

    if (price % 10000 != 0) {
        bill++;
    }

    int change = bill * 10000 - price;

    int coin[6] = { 500, 100, 50, 10, 5, 1 };

    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        cnt += change / coin[i];
        change %= coin[i];
    }

    cout << bill << " " << cnt;

    return 0;
}