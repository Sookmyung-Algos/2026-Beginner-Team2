#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> color(5);
    vector<int> num(5);

    int colorCount[4] = {};
    int numberCount[10] = {};

    for (int i = 0; i < 5; i++) { //입력
        cin >> color[i] >> num[i];

        numberCount[num[i]]++;

        if (color[i] == 'R') colorCount[0]++;
        else if (color[i] == 'B') colorCount[1]++;
        else if (color[i] == 'Y') colorCount[2]++;
        else colorCount[3]++;
    }

    sort(num.begin(), num.end());

    bool sameColor = false; //5장이 모두 같은 색이면 true

    for (int i = 0; i < 4; i++) {
        if (colorCount[i] == 5)
            sameColor = true;
    }

    bool straight = true; //5장이 모두 연속적인 숫자이면 true

    for (int i = 1; i < 5; i++) {
        if (num[i] != num[i - 1] + 1) {
            straight = false;
            break;
        }
    }

    // ① 같은 색 5개 + 연속 5개
    if (sameColor && straight) {
        cout << 900 + num[4];
        return 0;
    }

    // ② 같은 숫자 4개
    for (int i = 1; i <= 9; i++) {
        if (numberCount[i] == 4) {
            cout << 800 + i;
            return 0;
        }
    }

    // ③ 같은 숫자 3개 + 같은 숫자 2개
    int three = 0;
    int two = 0;

    for (int i = 1; i <= 9; i++) {
        if (numberCount[i] == 3)
            three = i;
        if (numberCount[i] == 2)
            two = i;
    }

    if (three != 0 && two != 0) {
        cout << 700 + three * 10 + two;
        return 0;
    }

    // ④ 같은 색 5개
    if (sameColor) {
        cout << 600 + num[4];
        return 0;
    }

    // ⑤ 숫자 연속 5개
    if (straight) {
        cout << 500 + num[4];
        return 0;
    }

    // ⑥ 같은 숫자 3개
    if (three != 0) {
        cout << 400 + three;
        return 0;
    }

    // ⑦ 같은 숫자 2개 + 또 다른 2개
    vector<int> pairs;

    for (int i = 1; i <= 9; i++) {
        if (numberCount[i] == 2)
            pairs.push_back(i);
    }

    if (pairs.size() == 2) {
        sort(pairs.begin(), pairs.end());

        cout << 300 + pairs[1] * 10 + pairs[0];
        return 0;
    }

    // ⑧ 같은 숫자 2개
    if (pairs.size() == 1) {
        cout << 200 + pairs[0];
        return 0;
    }

    // ⑨ 그 외
    cout << 100 + num[4];

    return 0;
}
