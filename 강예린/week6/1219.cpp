#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, C; //행, 열
	int paperCount, wrongCount; //사용할 색종이 수, 잘못 칠해진 칸 수
	cin >> R >> C;
	cin >> paperCount;
	cin >> wrongCount;

	vector<int> arr(C+1);

	int paperSize = 0;
	for (int i = 0; i < wrongCount; i++) {
		int r, c;
		cin >> r >> c;
		if (paperSize < r)paperSize = r;
		arr[c] = -1;
	}

	while(1){
		int start = 1;
		int end = C;
		int count = 0;
		while (start <= end) {
			if (arr[start] == -1) {
				count++;
				start += paperSize;
				continue;
			}
			start++;
		}
		if (count <= paperCount) break;
		else paperSize++;
	}

	cout << paperSize;
	return 0;
}