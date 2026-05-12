#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;

    set<int> s;

    for (int i = 0; i < Q; i++) {
        char c;
        int x;

        cin >> c >> x;

        if (c == 'i') {
            s.insert(x);
        }
        else if (c == 'r') {
            s.erase(x);
        }
    }

    for (int x : s) {
        cout << x << " ";
    }

    return 0;
}