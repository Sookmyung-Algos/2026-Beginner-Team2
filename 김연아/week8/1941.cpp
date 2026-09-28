#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; //충분히 큰 값으로 초기화 (무한대 역할)

//(비용, 정점 번호) 저장하기 위한 pair
typedef pair<int, int> Edge;

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    //인접 리스트로 그래프 표현: graph[u] = list of (v, cost)
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({ v, cost }); //단방향 간선
    }

    //최단 거리 테이블 초기화
    vector<int> dist(n + 1, INF);

    //최소 힙 우선순위 큐: {현재까지의 비용, 정점}
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    //시작 정점(1번) 설정
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        //큐에서 꺼낸 거리 > 이미 기록된 최단 거리이면 -> 이미 처리된 경로이므로 스킵
        if (current_dist > dist[u]) continue;

        //인접한 노드들 확인
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int cost = edge.second;

            //u를 거쳐서 v로 가는 거리가 기존 dist[v]보다 짧은 경우 갱신
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({ dist[v], v });
            }
        }
    }

    //1번에서 N번으로 가는 최단 거리 출력
    cout << dist[n] << "\n";

    return 0;
}