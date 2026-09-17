#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rows, cols;
int paper_limit;
int wrong_cnt;
vector<int> cols_pos;

bool canCover(int size) {
    int used = 0;
    int covered_until = 0;

    for (int col : cols_pos) {
        if (col > covered_until) {
            used++;
            covered_until = col + size - 1;
        }
    }

    return used <= paper_limit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> rows >> cols)) return 0;
    cin >> paper_limit;
    cin >> wrong_cnt;

    int max_row = 0;
    for (int i = 0; i < wrong_cnt; i++) {
        int r, c;
        cin >> r >> c;
        max_row = max(max_row, r);
        cols_pos.push_back(c);
    }

    sort(cols_pos.begin(), cols_pos.end());

    int left = max_row;
    int right = max(rows, cols);
    int ans = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canCover(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}