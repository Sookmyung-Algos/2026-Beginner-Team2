#include <iostream>
using namespace std;
#include <vector>
#include <string> 
#include <algorithm> //max, min 함수 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    string table; //문자열 입력 
    cin >> table;

    int count = 0;

    // 사람을 만나면 왼쪽부터 k 범위 내에서 햄버거 찾기
    for (int i = 0; i < N; i++) {
        if (table[i] == 'P') {
            //인덱스는 0보다 작아질수 x, 인덱스는 N-1 보다 커질 수 x
            for (int j = max(0, i - K); j <= min(N - 1, i + K); j++) {
                if (table[j] == 'H') {
                    table[j] = 'X'; //먹은 햄버거 표시
                    count++;
                    break; //한 사람은 하나만 먹음
                }
            }
        }
    }

    cout << count << "\n";
    return 0;
}