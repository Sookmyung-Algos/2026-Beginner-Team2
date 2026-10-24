#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 충분히 큰 값 설정

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 그래프 초기화 (자기 자신은 0, 나머지는 INF)
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 다중 간선이 있을 수 있으므로 최솟값 저장
        dist[u][v] = min(dist[u][v], w);
    }

    // 플로이드-와샬 DP 알고리즘 (거쳐가는 노드 k가 최외각 루프)
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 결과 출력 (경로가 없는 경우 0 출력)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}