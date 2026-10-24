#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선 정보 (시작, 끝, 비용)
struct Edge {
    int u, v, cost;

    // 비용이 적은 순서로 정렬
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
        return true; // 성공적으로 연결함
    }
    return false; // 이미 같은 그룹 (연결하면 사이클 발생)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Edge> edges;

    // 1. 행렬 형태로 입력받아 간선 리스트 만들기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;
            // 중복 및 자기 자신 제외를 위해 i < j 조건만 추가
            if (i < j) {
                edges.push_back({ i, j, cost });
            }
        }
    }

    // 2. 비용이 싼 간선부터 정렬
    sort(edges.begin(), edges.end());

    // 3. 분리집합 초기화
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 4. 제일 싼 간선부터 연결하기
    int total_cost = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (unite(edges[i].u, edges[i].v)) {
            total_cost += edges[i].cost;
        }
    }

    cout << total_cost << "\n";

    return 0;
}