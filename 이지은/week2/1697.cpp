#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> qu;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char cmd;
        cin >> cmd;

        if (cmd == 'i') {
            int num;
            cin >> num;
            qu.push(num);
        }
        else if (cmd == 'o') {
            if (qu.empty()) {
                cout << "empty" << endl;
            }
            else {
                cout << qu.front() << endl;
                qu.pop();
            }
        }
        else if (cmd == 'c') {
            cout << qu.size() << endl;
        }
    }

    return 0;
}