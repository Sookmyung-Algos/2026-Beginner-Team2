#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> S(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }

    const int INF = INT_MAX;

    // dist[i] = 1번 역에서 i번 역까지의 최소 시간
    vector<int> dist(N + 1, INF);

    // parent[i] = i번 역에 오기 직전의 역
    vector<int> parent(N + 1, -1);

    // {현재까지 걸린 시간, 현재 역}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int currentCost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (currentCost > dist[current])
            continue;

        for (int next = 1; next <= N; next++) {
            if (S[current][next] == 0)
                continue;

            int nextCost = currentCost + S[current][next];

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                parent[next] = current;
                pq.push({ nextCost, next });
            }
        }
    }

    // 최단 경로 복원
    vector<int> path;

    int current = M;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    // 최소 시간
    cout << dist[M] << '\n';

    // 최단 경로
    for (int station : path) {
        cout << station << ' ';
    }

    return 0;
}