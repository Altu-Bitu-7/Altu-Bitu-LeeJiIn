#include <iostream>

using namespace std;

const int MAX = 28;

int bitCount (int n) {
	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		if (n & (1 << i)) {
			cnt++;
		}
	}
	
	return cnt;
}

int minCount (int n, int k) {
	int required = 0; // 상점에서 사야하는 최소 물병 개수
	while (true) {
		if (bitCount(n + required) <= k) {
			return required;
		}
		required++;
	}
}

int main() {
	int n, k;

	// 입력
	cin >> n >> k;

	// 연산 & 출력
	cout << minCount(n, k);

	return 0;
}