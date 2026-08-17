#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int p = a + b * c;
    int q = a * (b + c);
    int r = a * b * c;
    int x = (a + b) * c;
    int y = a + b + c;
    int z = a * b + c;

    int max_val = p;
    if (max_val < q) max_val = q;
    if (max_val < r) max_val = r;
    if (max_val < x) max_val = x;
    if (max_val < y) max_val = y;
    if (max_val < z) max_val = z;

    cout << max_val << endl;

    return 0;
}