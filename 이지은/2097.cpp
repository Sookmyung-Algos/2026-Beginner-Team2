#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, destination;
    cin >> n >> destination;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> cost[i][j];

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(n + 1, INF);
    vector<int> previous(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (int v = 1; v <= n; ++v) {
            if (u == v) continue;
            long long nd = d + cost[u][v];
            if (nd < dist[v]) {
                dist[v] = nd;
                previous[v] = u;
                pq.push({ nd, v });
            }
        }
    }

    cout << dist[destination] << '\n';
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v]) path.push_back(v);
    for (int i = (int)path.size() - 1; i >= 0; --i)
        cout << path[i] << (i == 0 ? '\n' : ' ');
    return 0;
}