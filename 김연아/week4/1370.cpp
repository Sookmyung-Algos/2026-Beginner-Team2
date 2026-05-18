#include <iostream>
using namespace std;
#include <vector>
#include <tuple> //참고로 c언어에는 튜플x, 구조체만o 
#include <algorithm> //sort 

// 비교 함수 정의
bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) { //튜플 두개 (원본 직접 참조)
    // 종료시간 기준 오름차순
    if (get<2>(a) == get<2>(b)) {
        return get<1>(a) < get<1>(b); // 종료시간 같으면 시작시간 기준
    }
    return get<2>(a) < get<2>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<tuple<int, int, int>> meetings(n); //{ (번호, 시작시간, 종료시간), (), (), ...} 꼴

    for (int i = 0; i < n; i++) {
        int num, start, end;
        cin >> num >> start >> end;
        meetings[i] = make_tuple(num, start, end); //튜플 초기화하는 함수
    }

    // 종료 시간을 기준으로 오름차순 정렬
    sort(meetings.begin(), meetings.end(), compare);

    int count = 0;
    int last_end = 0;
    vector<int> selected; // 선택된 회의 번호 저장

    for (int i = 0; i < n; i++) { //get<index>(tuple) 로 튜플 원소에 접근
        if (get<1>(meetings[i]) >= last_end) { // 시작시간 >= 마지막 종료시간
            count++;
            last_end = get<2>(meetings[i]); // 종료시간 갱신
            selected.push_back(get<0>(meetings[i])); // 회의 번호 저장
        }
    }

    cout << count << endl;
    for (int i : selected) {
        cout << i << " ";
    }
    return 0;
}