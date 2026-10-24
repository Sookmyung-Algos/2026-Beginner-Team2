#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// x가 속한 그룹의 대표(부모) 찾기
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

// a와 b를 같은 그룹으로 합치기
void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootB] = rootA; // 한쪽 대표를 다른 쪽에 붙임
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 1. 초기화: 처음엔 각자 자기 자신이 대표
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 2. 입력받은 학생 쌍을 같은 그룹으로 합치기
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }

    // 3. 종교(그룹) 개수 세기: 자기 자신이 대표인 노드의 개수
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}