#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int k;
	cin >> n >> k;

	vector<char> table(n);
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (table[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) { //¸Ç ¿ÞÂÊ ÇÜ¹ö°ÅºÎÅÍ ¸ÔÀ½
				if (j >= 0 && j < n) {
					if (table[j] == 'H') {
						count++;
						table[j] = 'X'; 
						break;          
					}
				}
			}
		}
	}

	cout << count;
	return  0;


}