#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;


struct Patient {
    string name;
    int age;
    double blood;

  
    bool operator<(const Patient& other) const {
        if (this->age != other.age) {
            return this->age < other.age; 
        }
        return this->blood > other.blood;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<Patient> pq;
    map<string, pair<int, double>> latestInfo; 

    int Q;
    cin >> Q;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            string name;
            int age;
            double blood;
            cin >> name >> age >> blood;

         
            latestInfo[name] = { age, blood };
          
            pq.push({ name, age, blood });
        }
        else if (cmd == "pop") {
            while (!pq.empty()) {
                Patient top = pq.top();
                pq.pop();

                if (latestInfo.count(top.name) &&
                    latestInfo[top.name].first == top.age &&
                    latestInfo[top.name].second == top.blood) {

                    cout << top.name << " " << top.age << " ";
                    printf("%.1f\n", top.blood); 
                    break;
                }
              
            }
        }
    }
    return 0;
}