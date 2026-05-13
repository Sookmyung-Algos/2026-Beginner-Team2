#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> m;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'a') {
            int x;
            cin >> x;
            m[x]++;
        }
        else if (cmd == 'f') {
            int x;
            cin >> x;
            if (m.find(x) != m.end()) {

                cout << "YES " << m[x] << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
        else if (cmd == 'c') {
            cout << m.size() << "\n";
        }
    }
    return 0;
}