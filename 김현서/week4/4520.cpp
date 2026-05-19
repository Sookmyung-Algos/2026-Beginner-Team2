#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, k;
    cin >> N >> k;

    string s;
    cin >> s;

    int answer = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'P') {

            int start = i - k;
            int end = i + k;

            if (start < 0) start = 0;
            if (end >= N) end = N - 1;

            for (int j = start; j <= end; j++) {
                if (s[j] == 'H') {
                    s[j] = 'X';
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer;

    return 0;
}