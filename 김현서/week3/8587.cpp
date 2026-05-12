#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Patient {
    string name;
    int age;
    double blood;
};

struct cmp {

    bool operator()(Patient a, Patient b) {
        if (a.blood == b.blood) {
            return a.age < b.age;
        }


        return a.blood < b.blood;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    priority_queue<Patient, vector<Patient>, cmp> pq;


    for (int i = 0; i < Q; i++) {

        string cmd;
        cin >> cmd;


        if (cmd == "push") {

            Patient p;

            cin >> p.name;
            cin >> p.age;
            cin >> p.blood;

            pq.push(p);
        }


        else if (cmd == "pop") {

            if (!pq.empty()) {

                cout << pq.top().name << "\n";

                pq.pop();
            }
        }
    }

    return 0;
}