#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
typedef pair<int, int> Edge;

//다익스트라 함수
vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    if (!(cin >> n >> m >> x)) return 0;

    //정방향 그래프와 역방향 그래프
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<vector<pair<int, int>>> rev_graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({ v, cost });     // 정방향: u -> v
        rev_graph[v].push_back({ u, cost }); // 역방향: v -> u
    }

    //1. X번 마을에서 각 마을로 돌아가는 최단 거리 (X -> i)
    vector<int> dist_to_home = dijkstra(x, n, graph);

    //2. 각 마을에서 X번 마을로 가는 최단 거리 (i -> X)
    //   역방향 그래프에서 X를 시작점으로 다익스트라를 수행하면 됨
    vector<int> dist_to_party = dijkstra(x, n, rev_graph);

    //왕복 시간 중 최댓값 탐색
    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        int total_time = dist_to_party[i] + dist_to_home[i];
        max_time = max(max_time, total_time);
    }

    cout << max_time << "\n";

    return 0;
}