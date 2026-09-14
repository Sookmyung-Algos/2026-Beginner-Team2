#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> colors(5);
    vector<int> numbers(5);
    int num_cnt[10] = { 0 }; // 1부터 9까지 숫자 등장 횟수

    for (int i = 0; i < 5; i++) {
        cin >> colors[i] >> numbers[i];
        num_cnt[numbers[i]]++;
    }

    // 숫자 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    // 1. 색깔이 모두 같은지 판별
    bool is_same_color = true;
    for (int i = 1; i < 5; i++) {
        if (colors[i] != colors[0]) {
            is_same_color = false;
            break;
        }
    }

    // 2. 숫자가 5개 연속적인지 판별
    bool is_consecutive = true;
    for (int i = 0; i < 4; i++) {
        if (numbers[i] + 1 != numbers[i + 1]) {
            is_consecutive = false;
            break;
        }
    }

    // 3. 숫자 등장 횟수별 파악
    int count4 = 0;           // 4장 같은 숫자
    int count3 = 0;           // 3장 같은 숫자
    vector<int> count2_nums;  // 2장 같은 숫자들 (내림차순 저장용)

    for (int i = 9; i >= 1; i--) {
        if (num_cnt[i] == 4) count4 = i;
        else if (num_cnt[i] == 3) count3 = i;
        else if (num_cnt[i] == 2) count2_nums.push_back(i);
    }

    int max_num = numbers[4]; // 가장 큰 숫자
    int score = 0;

    // 규칙 ①: 모두 같은 색 + 연속적
    if (is_same_color && is_consecutive) {
        score = max_num + 900;
    }
    // 규칙 ②: 4장의 숫자가 같음
    else if (count4 > 0) {
        score = count4 + 800;
    }
    // 규칙 ③: 3장 같고 + 나머지 2장 같음
    else if (count3 > 0 && count2_nums.size() == 1) {
        score = count3 * 10 + count2_nums[0] + 700;
    }
    // 규칙 ④: 5장의 색깔이 모두 같음
    else if (is_same_color) {
        score = max_num + 600;
    }
    // 규칙 ⑤: 숫자가 연속적임
    else if (is_consecutive) {
        score = max_num + 500;
    }
    // 규칙 ⑥: 3장의 숫자가 같음
    else if (count3 > 0) {
        score = count3 + 400;
    }
    // 규칙 ⑦: 2장 같음 + 또 다른 2장 같음 (투 페어)
    else if (count2_nums.size() == 2) {
        // count2_nums는 내림차순으로 탐색했으므로 [0]이 큰 숫자, [1]이 작은 숫자
        score = count2_nums[0] * 10 + count2_nums[1] + 300;
    }
    // 규칙 ⑧: 2장의 숫자가 같음 (원 페어)
    else if (count2_nums.size() == 1) {
        score = count2_nums[0] + 200;
    }
    // 규칙 ⑨: 그 외
    else {
        score = max_num + 100;
    }

    cout << score << "\n";

    return 0;
}