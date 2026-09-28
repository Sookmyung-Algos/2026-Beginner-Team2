#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> grid(5);
int answer = 0;

void countGroups(int next, int chosen, int mask, int sCount) {
    if (chosen == 7) {
        if (sCount < 4) return;
        int start = __builtin_ctz((unsigned)mask);
        bool visited[25] = {};
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int connected = 0;
        const int dr[4] = { -1, 1, 0, 0 };
        const int dc[4] = { 0, 0, -1, 1 };
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ++connected;
            int r = cur / 5, c = cur % 5;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                int nxt = nr * 5 + nc;
                if ((mask & (1 << nxt)) && !visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        if (connected == 7) ++answer;
        return;
    }
    for (int i = next; i <= 25 - (7 - chosen); ++i) {
        countGroups(i + 1, chosen + 1, mask | (1 << i),
            sCount + (grid[i / 5][i % 5] == 'S'));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (string& row : grid) cin >> row;
    countGroups(0, 0, 0, 0);
    cout << answer << '\n';
    return 0;
}