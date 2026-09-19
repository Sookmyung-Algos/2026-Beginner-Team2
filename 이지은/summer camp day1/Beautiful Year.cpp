#include <iostream>
#include <string>
using namespace std;


int main() {
	//년도 입력받기
	string year;
	
	//입력받은 연도 +1을 해주고 다 다른지 확인 
	//다르지 않으면 계속 +1을 해가면서 다 다를떄까지 계산

        cin >> year; // 년도 입력받기

        // 1. 입력받은 문자열 연도를 정수로 바꾸고 +1 시작
        int num = stoi(year) + 1;

        while (true) {
            string current = to_string(num);

            if (current[0] != current[1] && current[0] != current[2] && current[0] != current[3] &&
                current[1] != current[2] && current[1] != current[3] &&
                current[2] != current[3]) {

                // 3. 다 다르면 출력하고 반복문 탈출!
                cout << current << "\n";
                break;
            }
            num++;
        }

        return 0;
    }