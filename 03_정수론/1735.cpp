#include <iostream>
#include <algorithm>

using namespace std;

int getMax (int b1, int b2) {
	if (b2 == 0) {
		return b1;
	}
	return getMax(b2, b1 % b2);
}

int main() {
	// 입력
	int a1, b1, a2, b2;
	cin >> a1 >> b1; // 첫번째 분자, 분모
	cin >> a2 >> b2; // 두번째 분자, 분모

	// 연산
	int gcd = getMax(max(b1, b2), min(b1, b2)); // 최대공약수
	int lcm = b1 * b2 / gcd; // 최소공배수
	int aa1 = lcm / b1 * a1; // 최소공배수로 통분해준 분자1
	int aa2 = lcm / b2 * a2; // 최소공배수로 통분해준 분자2
	int a = aa1 + aa2; // 아직 기약분수로 만들지 않은 분자
	int gcd2 = getMax(max(a, lcm), min(a, lcm)); // 더한 분수의 최대공약수
	int aa = a / gcd2; // 기약분수로 만든 분자
	int bb = lcm / gcd2; // 기약분수로 만든 분모

	// 출력
	cout << aa << " " << bb;

	return 0;
}