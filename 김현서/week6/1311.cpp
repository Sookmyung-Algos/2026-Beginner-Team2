#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char color[5];
    int num[5];
    int color_cnt[26] = { 0 };
    int num_cnt[10] = { 0 };

    for (int i = 0; i < 5; i++) {
        cin >> color[i] >> num[i];
        color_cnt[color[i] - 'A']++;
        num_cnt[num[i]]++;
    }

    sort(num, num + 5);

    bool same_color = false;
    for (int i = 0; i < 26; i++) {
        if (color_cnt[i] == 5) same_color = true;
    }

    bool consecutive = true;
    for (int i = 0; i < 4; i++) {
        if (num[i + 1] != num[i] + 1) {
            consecutive = false;
            break;
        }
    }

    int four_num = 0;
    int three_num = 0;
    vector<int> pairs;

    for (int i = 1; i <= 9; i++) {
        if (num_cnt[i] == 4) four_num = i;
        else if (num_cnt[i] == 3) three_num = i;
        else if (num_cnt[i] == 2) pairs.push_back(i);
    }

    int score = 0;

    if (same_color && consecutive) {
        score = num[4] + 900;
    }
    else if (four_num) {
        score = four_num + 800;
    }
    else if (three_num && pairs.size() == 1) {
        score = three_num * 10 + pairs[0] + 700;
    }
    else if (same_color) {
        score = num[4] + 600;
    }
    else if (consecutive) {
        score = num[4] + 500;
    }
    else if (three_num) {
        score = three_num + 400;
    }
    else if (pairs.size() == 2) {
        score = max(pairs[0], pairs[1]) * 10 + min(pairs[0], pairs[1]) + 300;
    }
    else if (pairs.size() == 1) {
        score = pairs[0] + 200;
    }
    else {
        score = num[4] + 100;
    }

    cout << score << "\n";

    return 0;
}