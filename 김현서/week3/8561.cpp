#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> m;

    string name;

    int line = 1;

    while (cin >> name) {

        if (name == "end") {
            break;
        }
        m[name] = line;

        line++;
    }
    cout << m.size() << "\n";


    for (auto it = m.begin(); it != m.end(); it++) {

        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}