#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    map<int, int> m;

    for (int i = 0; i < Q; i++) {

        char s;
        cin >> s;

        if (s == 'a') {

            int x;
            cin >> x;

            m[x]++;
        }
        else if (s == 'f') {

            int x;
            cin >> x;

            if (m.count(x)) {

                cout << "YES " << m[x] << "\n";
            }
            else {

                cout << "NO\n";
            }
        }
        else if (s == 'c') {

            cout << m.size() << "\n";
        }
    }

    return 0;
}