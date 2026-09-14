#include <iostream>
using namespace std;

const long long MOD = 20091024;

long long power(long long x, long long y) {
	if (y == 0) return 1;

	long long half = power(x, y / 2);
	long long result = (half * half) % MOD;

	if (y % 2 == 1) 
		result = (result * x) % MOD;
	
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	 
	long long x, y;
	cin >> x >> y;
	cout << power(x, y);

	return 0;
	
}