#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long x;
    long long answer = 1;
    int y;
    cin >> x >> y;
    if (x == 0 && y == 0) answer = 1;
    else {
        while (y--) {
            answer = answer * x;
            //cout << answer << " "; //µð¹ö±ë
            if (answer >= 20091024) answer %= 20091024;
        }
    }
    cout << answer;
}
