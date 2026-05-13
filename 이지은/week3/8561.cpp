#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> m;
    int Q;
    cin >> Q;

    while (Q--) {
        char cmd;
        string name, num;
        cin >> cmd;

        if (cmd == 'i') { 
            cin >> name >> num;
            m[name] = num;
        }
        else if (cmd == 'r') { 
            cin >> name;
            m.erase(name);
        }
        else if (cmd == 's') { 
            cin >> name;
            if (m.find(name) != m.end()) {
                cout << m[name] << "\n";
            }
            else {
                cout << "Not Found\n";
            }
        }
    }
    return 0;
}