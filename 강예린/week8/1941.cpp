#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to;
    int cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({ b, c });
    }

    vector<int> dist(N + 1, INF);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // 1번 정점에서 시작
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        // 이미 더 짧은 경로가 있다면 무시
        if (currentCost > dist[current])
            continue;

        // 현재 정점에서 연결된 간선 확인
        for (Edge edge : graph[current]) {
            int next = edge.to;
            int nextCost = currentCost + edge.cost;

            // 더 짧은 경로를 발견했다면 갱신
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }

    cout << dist[N];

    return 0;
}