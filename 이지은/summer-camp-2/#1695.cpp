#include <iostream>
#include <string>
#include <algorithm> // std::sort 함수만 가져와서 사용

using namespace std;

int N;
int map_matrix[30][30];
bool visited[30][30];
int house_count = 0;

// 각 단지의 집 개수를 저장할 일반 1차원 배열
int complex_sizes[1000];
int complex_total = 0; // 단지가 총 몇 개인지 세는 변수

// 상, 하, 좌, 우 이동
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
    visited[x][y] = true;
    house_count++; // 집 개수 +1

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 지도 범위 안이고, 집이 있고(1), 방문 안 한 곳이면 이동
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map_matrix[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map_matrix[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map_matrix[i][j] == 1 && !visited[i][j]) {
                house_count = 0; 
                dfs(i, j);       

                complex_sizes[complex_total] = house_count;
                complex_total++;
            }
        }
    }


    sort(complex_sizes, complex_sizes + complex_total);

    cout << complex_total << "\n";

    for (int i = 0; i < complex_total; i++) {
        cout << complex_sizes[i] << "\n";
    }

    return 0;
}