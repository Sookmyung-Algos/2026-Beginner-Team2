#include <iostream>     
#include <vector>      
#include <algorithm> // sort 
using namespace std;

int N;                   // 지도 크기 N
vector<string> grid;     // 지도 데이터 (문자열로 저장)
vector<vector<bool>> visited; // 방문 여부 체크
int dx[4] = { 1, -1, 0, 0 };    // 상하좌우 이동 (x 방향)
int dy[4] = { 0, 0, 1, -1 };    // 상하좌우 이동 (y 방향)

// DFS 함수: (x,y) 위치에서 연결된 집들을 탐색
int dfs(int x, int y) {
    visited[x][y] = true;  // 현재 위치 방문 처리
    int count = 1;          // 현재 집 포함 -> 집 개수 1부터 시작
    for (int dir = 0; dir < 4; dir++) {   // 4방향 탐색
        int nx = x + dx[dir];             // 다음 x 좌표
        int ny = y + dy[dir];             // 다음 y 좌표
        // 범위 안에 있고, 아직 방문하지 않았으며 집이 있는 경우
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (!visited[nx][ny] && grid[nx][ny] == '1') {
                count += dfs(nx, ny);     // DFS 재귀 호출, 연결된 집 개수 누적
            }
        }
    }
    return count;   // 연결된 집 개수 반환
}

int main() {
    cin >> N;
    grid.resize(N);  //N 입력받았으니까 grid 벡터 크기지정 
    visited.assign(N, vector<bool>(N, false)); // 방문 여부 초기화

    for (int i = 0; i < N; i++) {
        cin >> grid[i];  // 지도 데이터 입력 (문자열)
    }

    vector<int> complexes;   // 각 단지의 집 개수 저장할 벡터(동적배열)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 집이 있고 아직 방문하지 않았다면 새로운 단지 발견
            if (!visited[i][j] && grid[i][j] == '1') {
                int houses = dfs(i, j);   //DFS로 단지 탐색, 집 개수 반환
                complexes.push_back(houses); //단지 내 집 개수 저장
            }
        }
    }

    sort(complexes.begin(), complexes.end()); //오름차순 정렬
    cout << complexes.size() << "\n"; //총 단지 수 출력
    for (int c : complexes) cout << c << "\n"; //각 단지 집 개수 출력
    return 0;
}
