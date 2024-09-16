#include <iostream>

using namespace std;

bool isValid (int cur) {
	while (cur >= 666) {
		if (cur % 1000 == 666) {
			return true;
		}
		cur /= 10;
	}
	return false;
}

int solution (int &n) {
	int cur = 666;
	int cnt = 0;

	while (true) {
		if (isValid(cur)) {
			cnt++;
		}
		if (cnt == n) {
			return cur;
		}
		cur++;
	}
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);

	return 0;
}