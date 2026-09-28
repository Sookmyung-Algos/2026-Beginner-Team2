#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits>
using namespace std;

struct Edge { int to; long long cost; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost != dist[u]) continue;
        for (const Edge& e : graph[u]) {
            if (dist[e.to] > cost + e.cost) {
                dist[e.to] = cost + e.cost;
                pq.push({ dist[e.to], e.to });
            }
        }
    }
    cout << dist[n] << '\n';
    return 0;
}