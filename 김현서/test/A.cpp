#include <iostream>
using namespace std;

int N, M;
int dice[10];
bool visited[10];

void mode1(int cnt) {
    if (cnt == N) {
        for (int i = 0; i < N; i++) cout << dice[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= 6; i++) {
        dice[cnt] = i;
        mode1(cnt + 1);
    }
}

void mode2(int cnt, int start) {
    if (cnt == N) {
        for (int i = 0; i < N; i++) cout << dice[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i <= 6; i++) {
        dice[cnt] = i;
        mode2(cnt + 1, i);
    }
}


void mode3(int cnt) {
    if (cnt == N) {
        for (int i = 0; i < N; i++) cout << dice[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= 6; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dice[cnt] = i;
            mode3(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    if (M == 1) mode1(0);
    else if (M == 2) mode2(0, 1);
    else if (M == 3) mode3(0);
    return 0;
}