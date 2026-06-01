
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int r, c, d, cost;
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) {
        return 0;
    }

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int sr, sc, sd;
    cin >> sr >> sc >> sd;
    sr--; sc--; sd--;

    int tr, tc, td;
    cin >> tr >> tc >> td;
    tr--; tc--; td--;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};


    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(4, false)));

    queue<State> q;
    q.push({sr, sc, sd, 0});
    visited[sr][sc][sd] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.r == tr && cur.c == tc && cur.d == td) {
            cout << cur.cost << "\n";
            return 0;
        }

        for (int k = 1; k <= 3; ++k) {
            int nr = cur.r + dr[cur.d] * k;
            int nc = cur.c + dc[cur.d] * k;

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (grid[nr][nc] == 1) {
                    break;
                }
                if (!visited[nr][nc][cur.d]) {
                    visited[nr][nc][cur.d] = true;
                    q.push({nr, nc, cur.d, cur.cost + 1});
                }
            } else {
                break;
            }
        }

 
        vector<int> next_dirs;
        if (cur.d == 0 || cur.d == 1) {
            next_dirs = {2, 3};
        } else {
            next_dirs = {0, 1};
        }

        for (int nd : next_dirs) {
            if (!visited[cur.r][cur.c][nd]) {
                visited[cur.r][cur.c][nd] = true;
                q.push({cur.r, cur.c, nd, cur.cost + 1});
            }
        }
    }

    return 0;
}
