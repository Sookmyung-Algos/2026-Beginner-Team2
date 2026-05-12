#include <iostream>
#include <iostream>
#include <stack>

using namespace std;


int target[1001];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> target[i];
    }

    stack<int> s;
    int now = 1; 
    int pos = 0; 


    for (int i = 0; i < N; i++) {
       
        s.push(now);
        cout << "i" << endl;
        now = now + 1;

      
        while (s.size() > 0 && s.top() == target[pos]) {
            s.pop();
            cout << "o" << endl;
            pos = pos + 1;
        }
    }

    return 0;
}