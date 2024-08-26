#include <iostream>
#include <map>

using namespace std;

int main() {
	// 입력
	int t, n;
	string outfit, outfit_types;
	cin >> t;
	while (t--) {
		int ans = 1;
		cin >> n;
		map<string, int> clothes;

		while (n--) {
			cin >> outfit >> outfit_types;
			clothes[outfit_types]++; // 그 종류의 옷 개수 + 1
		}

		// 연산
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			ans *= (iter -> second + 1); // 입을 수 있는 옷의 종류 (iter -> second) + 아무것도 입지 않는 경우 (1)
		}
		// 위의 for문이랑 같은 코드
		/* for (auto keys : clothes) {
			// map의 key 값으로 iterate
			ans *= keys.second + 1;
		} */

		ans--; // 알몸인 경우

		// 출력
		cout << ans << '\n';
	}

	return 0;
}