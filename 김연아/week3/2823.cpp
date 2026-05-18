#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm> //sort
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int price;
    cin >> price;

    int money[] = { 500, 100, 50, 10, 5, 1 };

    int tt_cash;
    tt_cash = (price % 10000 == 0) ? (price / 10000) : (price / 10000) + 1;
    int change = 0;

    price = tt_cash * 10000 - price;

    for (int i = 0 && price > 0; i < 6; i++) {
        if ((price / money[i]) != 0) {
            change += (price / money[i]);
            price %= money[i];
        }

    }
    cout << tt_cash << " " << change << "\n";
    return 0;
}