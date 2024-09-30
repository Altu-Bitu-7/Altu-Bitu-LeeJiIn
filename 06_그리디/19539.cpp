#include <iostream>

using namespace std;

bool solve (int sum, int odd) {
	if (sum % 3) { // 나무들 높이 합이 3의 배수여야 함
		return false;
	}
	if (odd > sum / 3) { // (sum / 3)은 물을 주는 횟수
		return false;
	}
	return true;
}

int main() {
	int n, sum = 0, odd = 0;

	// 입력 & 연산
	cin >> n;
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;
		sum += height;
		if (height % 2) // 홀수 높이의 개수 세기
			odd++;
	}

	// 출력
	solve(sum, odd) ? cout << "YES" : cout << "NO";

	return 0;
}