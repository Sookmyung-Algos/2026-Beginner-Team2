#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int wt[5] = {1,2,4,8,16}; //weight Type
	int wc[5]; //weight count

	for (int i = 0; i < 5; i++) {
		cin >> wc[i];
	}
	cin >> n;

	int count=0; 
	for (int i = 4; i >= 0; i--) {
		if (wc[i] >= n / wt[i]) {
			count += n / wt[i];
			n %= wt[i];
		}
		else {
			count += wc[i];
			n -= wc[i] * wt[i];
		}
	}
	

	if (n == 0) {
		cout << count;
	}
	else {
		cout << "impossible";
	}
	return 0;
}