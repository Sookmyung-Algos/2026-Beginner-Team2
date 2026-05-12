#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string target;
    cin >> target;

    stack<char> s;

    char next_val = 'A';
    int pos = 0;

    for (int i = 0; i < 3; i = i + 1) {

        s.push(next_val);
        cout << "i" << endl;
        next_val = next_val + 1;


        while (s.size() > 0 && s.top() == target[pos]) {
            cout << "o" << endl;
            s.pop();
            pos = pos + 1;
        }
    }

    return 0;
}
