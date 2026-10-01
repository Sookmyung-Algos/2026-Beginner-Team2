#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits>
using namespace std;

vector<long long> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(graph.size(), INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost != dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > cost + w)
            {
                dist[v] = cost + w;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    vector < vector < pair<int,
        int>>> graph(n + 1), reverseGraph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({ b, t });
        reverseGraph[b].push_back({ a, t });
    }

    vector<long long> fromX = dijkstra(graph, x);
    vector<long long> toX = dijkstra(reverseGraph, x);
    long long answer = 0;
    for (int i = 1; i <= n; ++i)
        answer = max(answer, fromX[i] + toX[i]);
    cout << answer << '\n';
    return 0;
}