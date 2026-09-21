#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Building {
    int x;
    int y;
};


bool compareBuild(Building a, Building b) {
    return a.x < b.x;
}

Building buildings[10005];
int dp[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> buildings[i].x >> buildings[i].y;
    }

 
    sort(buildings + 1, buildings + n + 1, compareBuild);

    for (int i = 1; i <= n; i++) {
        dp[i] = 2000000000; 
        int max_y = 0;

        
        for (int j = i; j >= 1; j--) {
            int current_y = abs(buildings[j].y);
            if (current_y > max_y) {
                max_y = current_y;
            }

         
            int width = buildings[i].x - buildings[j].x;
            int height = 2 * max_y;
            int cost = max(width, height);

            if (dp[j - 1] + cost < dp[i]) {
                dp[i] = dp[j - 1] + cost;
            }
        }
    }

    cout << dp[n] << "\n";

    return 0;
}