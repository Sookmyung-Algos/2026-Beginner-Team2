#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//거리 합이 int 범위를 넘을 수 있으므로 long long 사용
const long long INF = 1e18;

//{비용, 목적지 정점}
typedef pair<long long, int> Edge;

int main() {
    //빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    //인접 리스트
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({ v, cost });
    }

    //최단 거리 배열 초기화
    vector<long long> dist(n + 1, INF);

    //최소 힙: {현재까지의 누적 거리, 정점 번호}
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    //시작점 1번 설정
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        //꺼낸 거리가 이미 저장된 최단 거리보다 크다면 탐색 생략
        if (current_dist > dist[u]) continue;

        //인접한 정점 완화
        for (const auto& next : graph[u]) {
            int v = next.first;
            long long weight = next.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    //N번 정점까지의 최단 거리 출력
    cout << dist[n] << "\n";

    return 0;
}