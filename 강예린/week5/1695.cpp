#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int map[30][30];
bool visited[30][30];

//방향 배열
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int bfs(int startR, int startC) {
    queue<pair<int, int>> q;
    q.push({ startR, startC });
    visited[startR][startC] = true;

    int houseCount = 1;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                if (map[nr][nc] == 1 && !visited[nr][nc]) {
                    visited[nr][nc] = true; // 방문 처리
                    q.push({ nr, nc });       // 큐에 추가
                    houseCount++;           // 단지 내 집의 수 증가
                }
            }
        }
    }

    return houseCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    vector<int> complexSizes; // 각 단지의 크기를 저장할 벡터

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                complexSizes.push_back(bfs(i, j));
            }
        }
    }

    sort(complexSizes.begin(), complexSizes.end());//오르차순 정렬

    //출력
    cout << complexSizes.size() << "\n";

    for (int size : complexSizes) {
        cout << size << "\n";
    }

    return 0;
}