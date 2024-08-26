#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string guitar1, string guitar2) {
	int sum1 = 0;
	int sum2 = 0;
	
	if (guitar1.size() != guitar2.size()) {
		return guitar1.size() < guitar2.size();
	}

	for (int i = 0; i < guitar1.size(); i++) {
		if (guitar1[i] >= '0' && guitar1[i] <= '9') {
			sum1 += int(guitar1[i]) - 48;
		}

		if (guitar2[i] >= '0' && guitar2[i] <= '9') {
			sum2 += int(guitar2[i]) - 48;
		}
	}

	if (sum1 != sum2) {
		return sum1 < sum2;
	}

	return guitar1 < guitar2;
}

int main() {
	// 입력
	int n;
	cin >> n;
	vector<string> serial(n);
	for (int i = 0; i < n; i++) {
		cin >> serial[i];
	}
	
	// 연산
	sort(serial.begin(), serial.end(), cmp);

	// 출력
	for (int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}

	return 0;
}