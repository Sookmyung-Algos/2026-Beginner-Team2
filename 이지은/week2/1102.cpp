#include <iostream>

using namespace std;

int stack[100];
int top = -1;   

int main() {
   
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char cmd;
        cin >> cmd; 

        if (cmd == 'i') {
            int num;
            cin >> num;

            top = top + 1;     
            stack[top] = num;  
        }
        else if (cmd == 'o') {
           
            if (top == -1) {
                cout << "empty" << endl;
            }
            else {
                cout << stack[top] << endl; 
                top = top - 1;             
            }
        }
        else if (cmd == 'c') {
            cout << top + 1 << endl;
        }
    }

    return 0;
}
