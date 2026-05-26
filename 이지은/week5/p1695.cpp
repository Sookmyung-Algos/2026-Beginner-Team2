
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    auto bfs = [&](int start_r, int start_c) -> int {
        queue<pair<int, int>> q;
        q.push({start_r, start_c});
        visited[start_r][start_c] = true;
        int count = 1;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (grid[nr][nc] == '1' && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                        count++;
                    }
                }
            }
        }
        return count;
    };

    vector<int> complex_sizes;
    
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == '1' && !visited[r][c]) {
                complex_sizes.push_back(bfs(r, c));
            }
        }
    }

    sort(complex_sizes.begin(), complex_sizes.end());

    cout << complex_sizes.size() << "\n";
    for (int size : complex_sizes) {
        cout << size << "\n";
    }

    return 0;
}
