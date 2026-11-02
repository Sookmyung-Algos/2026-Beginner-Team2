
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 500000;

int tree[MAX * 4];

int query(int node, int start, int end, int left, int right) {
    // 범위를 벗어난 경우
    if (right < start || end < left)
        return 0;

    // 구간이 완전히 포함된 경우
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    int l = query(node * 2, start, mid, left, right);
    int r = query(node * 2 + 1, mid + 1, end, left, right);

    return max(l, r);
}

void update(int node, int start, int end, int idx, int value) {
    if (idx < start || idx > end)
        return;

    if (start == end) {
        tree[node] = max(tree[node], value);
        return;
    }

    int mid = (start + end) / 2;

    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> sortedA;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sortedA.push_back(A[i]);
    }

    // 좌표 압축
    sort(sortedA.begin(), sortedA.end());

    sortedA.erase(
        unique(sortedA.begin(), sortedA.end()),
        sortedA.end()
    );

    int K = sortedA.size();
    int answer = 0;

    // LIS 구하기
    for (int i = 0; i < N; i++) {

        // 현재 값의 압축된 인덱스
        int idx = lower_bound(
            sortedA.begin(), sortedA.end(), A[i]
        ) - sortedA.begin();

        // 현재 값보다 작은 값들의 LIS 최댓값 + 1
        int dp = query(1, 0, K - 1, 0, idx - 1) + 1;

        // 세그먼트 트리 갱신
        update(1, 0, K - 1, idx, dp);

        answer = max(answer, dp);
    }

    cout << answer << '\n';

    return 0;
}
