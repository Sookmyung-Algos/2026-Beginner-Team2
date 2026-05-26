#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int map[105][105];
bool visited[105][105][5]; // 행, 열, 1~4 방향

// 방향: 1동, 2서, 3남, 4북
int dr[] = { 0, 0, 0, 1, -1 };
int dc[] = { 0, 1, -1, 0, 0 };

// 로봇
struct Node {
    int r, c, dir, count;
};

// 왼쪽으로 90도 회전
int turnLeft(int dir) {
    if (dir == 1) return 4; // 동 -> 북
    if (dir == 2) return 3; // 서 -> 남
    if (dir == 3) return 1; // 남 -> 동
    if (dir == 4) return 2; // 북 -> 서
    return 0;
}

// 오른쪽으로 90도 회전
int turnRight(int dir) {
    if (dir == 1) return 3; // 동 -> 남
    if (dir == 2) return 4; // 서 -> 북
    if (dir == 3) return 2; // 남 -> 서
    if (dir == 4) return 1; // 북 -> 동
    return 0;
}

int bfs(int sr, int sc, int sDir, int tr, int tc, int tDir) {
    queue<Node> q;
    q.push({ sr, sc, sDir, 0 });
    visited[sr][sc][sDir] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        // 목표 상태에 도달한 경우
        if (current.r == tr && current.c == tc && current.dir == tDir) {
            return current.count;
        }

        // 1. Go k (현재 방향으로 1~3칸 전진)
        for (int k = 1; k <= 3; k++) {
            int nr = current.r + dr[current.dir] * k;
            int nc = current.c + dc[current.dir] * k;

            // 맵을 벗어난 경우 스킵
            if (nr <= 0 || nr > M || nc <= 0 || nc > N) break;

            // 벽(1)을 만나면 그 너머로 갈 수 없으므로 탐색 중지
            if (map[nr][nc] == 1) break;

            // 방문하지 않은 상태라면 큐에 추가
            if (!visited[nr][nc][current.dir]) {
                visited[nr][nc][current.dir] = true;
                q.push({ nr, nc, current.dir, current.count + 1 });
            }
        }

        // 2. Turn dir (왼쪽, 오른쪽 회전)
        int left = turnLeft(current.dir);
        int right = turnRight(current.dir);

        if (!visited[current.r][current.c][left]) {
            visited[current.r][current.c][left] = true;
            q.push({ current.r, current.c, left, current.count + 1 });
        }

        if (!visited[current.r][current.c][right]) {
            visited[current.r][current.c][right] = true;
            q.push({ current.r, current.c, right, current.count + 1 });
        }
    }

    return 0;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    // 공장 내 궤도 설치 상태 입력
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    int startR, startC, startDir;
    cin >> startR >> startC >> startDir;

    int targetR, targetC, targetDir;
    cin >> targetR >> targetC >> targetDir;

    // BFS 실행 및 결과 출력
    cout << bfs(startR, startC, startDir, targetR, targetC, targetDir) << "\n";

    return 0;
}