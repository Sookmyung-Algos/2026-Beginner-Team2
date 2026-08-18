#include <iostream>

using namespace std;

int a[30005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    // 1번 칸부터 n-1번 칸까지 입력받기
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    int current = 1; // 1번 칸에서 시작

    // 현재 위치가 목표 t보다 작을 동안 계속 이동
    while (current < t) {
        current = current + a[current];
    }

    // 도착했는지 확인
    if (current == t) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}