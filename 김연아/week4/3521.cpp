#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> //min 함수 

int main() {
    int a, b, c, d, e; // 1g, 2g, 4g, 8g, 16g 개수
    int N;
    cin >> a >> b >> c >> d >> e >> N;

    int weights[5] = { 16, 8, 4, 2, 1 };
    int counts[5] = { e, d, c, b, a }; // 큰 추부터 개수 저장
    int used = 0;

    for (int i = 0; i < 5; i++) {
        int need = N / weights[i]; // 현재 무게에서 필요한 개수
        int take = min(need, counts[i]); // 각 추의 개수와 비교
        used += take;
        N -= take * weights[i]; //N그램 갱신 
    }

    if (N == 0) cout << used << endl;
    else cout << "impossible" << endl; // 만들 수 없는 경우

    return 0;
}