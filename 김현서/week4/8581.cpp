#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int A[100000];
    int B[100000];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N);

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        answer += (long long)A[i] * B[i];
    }

    cout << answer;

    return 0;
}