#include <iostream>      
#include <queue> // BFS 큐 사용
#include <vector>   
using namespace std;

struct State {
    int x, y, dir, cnt;  //로봇 상태: 위치(x,y), 방향(dir), 명령 횟수(cnt)
};

int dx[5] = { 0, 0, 0, 1, -1 }; //방향별 x 변화량 (1:동, 2:서, 3:남, 4:북)
int dy[5] = { 0, 1, -1, 0, 0 }; //방향별 y 변화량 (0번쩨 인덱스 비워둠)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;   //세로 M, 가로 N

    // 궤도 내 숫자 입력받기 0: 갈 수 있음, 1: 벽
    vector<vector<int>> grid(M + 1, vector<int>(N + 1));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    // 출발 위치, 방향, 도착 위치, 방향 입력
    int sx, sy, sd, ex, ey, ed;
    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;

    // 방문 여부 체크 위치(x,y) 방향(dir) visited[x][y][dir] 꼴
    vector<vector<vector<bool>>> visited(M + 1, vector<vector<bool>>(N + 1, vector<bool>(5, false)));

    // BFS 큐 초기화
    queue<State> q;
    q.push({ sx, sy, sd, 0 }); //출발 상태 삽입
    visited[sx][sy][sd] = true; // 출발 상태 방문 처리

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        // 목표 상태에 도달하면 출력 후 종료
        if (cur.x == ex && cur.y == ey && cur.dir == ed) {
            cout << cur.cnt << "\n";
            return 0;
        }

        // --- Turn 명령 처리 ---
        int leftDir, rightDir;
        if (cur.dir == 1) { leftDir = 4; rightDir = 3; }   // 동쪽 → 왼쪽=북, 오른쪽=남
        else if (cur.dir == 2) { leftDir = 3; rightDir = 4; } // 서쪽 → 왼쪽=남, 오른쪽=북
        else if (cur.dir == 3) { leftDir = 1; rightDir = 2; } // 남쪽 → 왼쪽=동, 오른쪽=서
        else { leftDir = 2; rightDir = 1; } // 북쪽 → 왼쪽=서, 오른쪽=동

        // 왼쪽 회전
        if (!visited[cur.x][cur.y][leftDir]) {
            visited[cur.x][cur.y][leftDir] = true;
            q.push({ cur.x, cur.y, leftDir, cur.cnt + 1 });
        }
        // 오른쪽 회전
        if (!visited[cur.x][cur.y][rightDir]) {
            visited[cur.x][cur.y][rightDir] = true;
            q.push({ cur.x, cur.y, rightDir, cur.cnt + 1 });
        }

        // --- Go 명령 처리 (1~3칸) ---
        for (int k = 1; k <= 3; k++) {
            int nx = cur.x + dx[cur.dir] * k; // 현재 방향으로 k칸 이동
            int ny = cur.y + dy[cur.dir] * k;
            if (nx < 1 || nx > M || ny < 1 || ny > N) break; // 범위 밖이면 중단
            if (grid[nx][ny] == 1) break; // 벽이면 중단
            if (!visited[nx][ny][cur.dir]) {
                visited[nx][ny][cur.dir] = true;
                q.push({ nx, ny, cur.dir, cur.cnt + 1 }); // 이동 상태 큐에 삽입
            }
        }
    }
}
