#include <iostream>
using namespace std;

int n;
int paper[128][128];
int whiteCount = 0, blueCount = 0;

void dividePaper(int row, int col, int size) {
    int color = paper[row][col];
    bool uniform = true;
    for (int r = row; r < row + size && uniform; ++r)
        for (int c = col; c < col + size; ++c)
            if (paper[r][c] != color) {
                uniform = false;
                break;
            }

    if (uniform) {
        if (color == 0) ++whiteCount;
        else ++blueCount;
        return;
    }
    int half = size / 2;
    dividePaper(row, col, half);
    dividePaper(row, col + half, half);
    dividePaper(row + half, col, half);
    dividePaper(row + half, col + half, half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            cin >> paper[r][c];

    dividePaper(0, 0, n);
    cout << whiteCount << '\n' << blueCount << '\n';
    return 0;
}