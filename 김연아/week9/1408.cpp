#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> wire(N);

    for (int i = 0; i < N; i++) {
        cin >> wire[i].first >> wire[i].second;
    }

    // A 전봇대 위치를 기준으로 오름차순 정렬
    sort(wire.begin(), wire.end());

    // B 전봇대 위치의 LIS 구하기
    vector<int> lis;

    for (int i = 0; i < N; i++) {
        int x = wire[i].second;

        auto it = lower_bound(lis.begin(), lis.end(), x);

        if (it == lis.end()) {
            lis.push_back(x);
        }
        else {
            *it = x;
        }
    }

    // 제거해야 하는 전깃줄의 최소 개수
    cout << N - lis.size() << '\n';

    return 0;
}