#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; //전깃줄 개수
	cin >> n;

	vector<int> index; //a전봇대에서 전깃줄이 연결된 위치
	int line[501]; //line[a]=b , a-b 연결
	vector<int> arr; //LIS를 구해야할 수열

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		index.push_back(a);
		line[a] = b;
	}

	sort(index.begin(), index.end());
	for (int i = 0; i < n; i++) {
		arr.push_back(line[index[i]]);
	}

	vector<int> tails; //이분탐색을 이용하기 위한 tails벡터

	for (int x : arr) {
		auto it = lower_bound(tails.begin(), tails.end(), x);

		if (it == tails.end()) {
			tails.push_back(x);
		}
		else {
			*it = x;
		}
	}

	cout << tails.size();
	return 0;
}