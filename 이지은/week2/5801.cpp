#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 연산자별 우선순위 반환 함수
int getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '(') return 0;
    return -1;
}

int main() {
    string infix;
    cin >> infix;

    stack<char> s;

    for (char c : infix) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
        }
        else if (c == '(') {
            s.push(c);
        }
      
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); 
        }
   
        else {
            while (!s.empty() && getPriority(s.top()) >= getPriority(c)) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}