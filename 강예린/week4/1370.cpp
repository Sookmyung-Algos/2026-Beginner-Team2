#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
	int number;
	int start;
	int end;
};

bool cmp(const Meeting& a, const Meeting& b) { //종료시간이 빠른 순서로 정렬
	return a.end < b.end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Meeting> m(n);
	for (int i = 0; i < n; i++) {
		cin >> m[i].number >> m[i].start >> m[i].end;
	}
	sort(m.begin(), m.end(), cmp);

	vector<int> selected_ids; //배정한 회의 번호 
	int current_time = 0; //마지막 회의 종료시간

	for (int i = 0; i < n; i++) {
		if (m[i].start >= current_time) {
			selected_ids.push_back(m[i].number);
			current_time = m[i].end;
		}
	}

	cout << selected_ids.size() << "\n";
	for (int i = 0; i < selected_ids.size(); i++) {
		cout << selected_ids[i] << " ";
	}

	return 0;
}