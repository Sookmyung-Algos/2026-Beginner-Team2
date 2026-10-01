#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to;
    int cost;
};

vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    int N = graph.size() - 1;

    vector<int> dist(N + 1, INF);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (currentCost > dist[current])
            continue;

        for (Edge edge : graph[current]) {
            int next = edge.to;
            int nextCost = currentCost + edge.cost;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<Edge>> graph(N + 1);
    vector<vector<Edge>> reverseGraph(N + 1);

    for (int i = 0; i < M; i++) {
        int start, end, time;
        cin >> start >> end >> time;

        graph[start].push_back({ end, time });

        // 방향을 반대로 저장
        reverseGraph[end].push_back({ start, time });
    }

    // X → 모든 마을
    vector<int> fromX = dijkstra(X, graph);

    // 모든 마을 → X
    // 뒤집은 그래프에서 X → 모든 마을을 구하면 됨
    vector<int> toX = dijkstra(X, reverseGraph);

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, fromX[i] + toX[i]);
    }

    cout << answer;

    return 0;
}