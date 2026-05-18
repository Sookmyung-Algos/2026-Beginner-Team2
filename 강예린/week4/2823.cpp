#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int price;
	int coinType[] = {500, 100, 50, 10, 5, 1};

	cin >> price;

	int mCnt = price / 10000; //만원 장수
	if (price % 10000 != 0) { //예외) 딱 떨어지는 경우
		mCnt += 1; 
	} 

	int change = 10000 * mCnt - price;
	int cCnt = 0; //거스름돈 동전 개수

	for (int i = 0; i < 6; i++) {
		cCnt += change / coinType[i];
		change %= coinType[i];
	}
	cout << mCnt << " " << cCnt;
	return 0;
}