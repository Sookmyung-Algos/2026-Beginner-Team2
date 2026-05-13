#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) { 
        char cmd; 
        int k;  

        cin >> cmd >> k;

        if (cmd == 'i') {
            s.insert(k);
        }
        else if (cmd == 'r') {
            s.erase(k); 
        }
    }

    for (int n : s) {
        cout << n << " ";
    }

    return 0;
}