#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting {
    int num;
    int start;
    int end;
};

bool cmp(Meeting a, Meeting b) {
    if (a.end == b.end) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    Meeting arr[500];

    for (int i = 0; i < N; i++) {
        cin >> arr[i].num >> arr[i].start >> arr[i].end;
    }

    sort(arr, arr + N, cmp);

    int lastEnd = 0;
    int answer = 0;
    int selected[500];

    for (int i = 0; i < N; i++) {
        if (arr[i].start >= lastEnd) {
            selected[answer] = arr[i].num;
            answer++;
            lastEnd = arr[i].end;
        }
    }

    cout << answer << "\n";

    for (int i = 0; i < answer; i++) {
        cout << selected[i] << " ";
    }

    return 0;
}