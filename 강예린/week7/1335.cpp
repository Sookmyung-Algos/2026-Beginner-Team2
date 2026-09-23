#include <iostream>
#include <vector>
using namespace std;

int whiteCount = 0;
int blueCount = 0;

void divideConquer(vector<vector<int>> &paper, int r, int c, int size) { //Ω√¿€¡° (r, c)
	int color = paper[r][c];
	bool isSame = true;

	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (paper[i][j] != color) {
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	if (isSame) {
		if (color == 0) whiteCount++;
		else blueCount++;
		return;
	}

	int half = size / 2;
	divideConquer(paper, r, c, half);
	divideConquer(paper, r, c + half, half);
	divideConquer(paper, r + half, c, half);
	divideConquer(paper, r + half, c + half, half);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> paper;
	paper.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	divideConquer(paper, 0, 0, n);

	cout << whiteCount << '\n';
	cout << blueCount << '\n';
	return 0;



}