#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> //reverse 함수 

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    //인접 행렬 형태의 그래프 입력
    //정점 번호 1부터 시작하므로 크기 n + 1
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, 0); //경로 추적하기 위한 배열

    //최소 힙 큐: {현재까지의 비용, 정점 번호}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //1번 역(숙소)에서 출발
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        //인접 행렬이므로 1번부터 N번 역까지 모두 확인
        for (int v = 1; v <= n; v++) {
            int cost = graph[u][v];

            //자기 자신으로 가는 경우(cost == 0) or 길이 아예 없는 경우 건너뜀
            if (u == v || cost == 0) continue;

            //더 짧은 경로를 발견했다면 거리와 부모 노드 갱신
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                parent[v] = u; // v로 오기 직전의 역이 u임을 기록!!
                pq.push({ dist[v], v });
            }
        }
    }

    //1. 최소 시간 출력
    cout << dist[m] << "\n";

    //2. 경로 역추적
    vector<int> path;
    int curr = m; //목적지에서 시작
    while (curr != 0) {
        path.push_back(curr);
        curr = parent[curr]; //직전 역으로 거슬러 올라감 (시작점의 parent= 0)
    }

    //역추적했으므로 순서 반대(목적지->시작점) 이를 뒤집어줌.
    reverse(path.begin(), path.end());

    //경로 출력
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}