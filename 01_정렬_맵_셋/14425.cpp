#include <iostream>
#include <set>

using namespace std;

int main() {
	// 입력 & 연산
	int n, m;
	cin >> n >> m;
	set<string> s;
	int count = 0;

	string nstring, mstring;
	while (n--) {
		cin >> nstring;
		s.insert(nstring);
	}
	while (m--) {
		cin >> mstring;
		if (s.find(mstring) != s.end()) {
			count++;
		}
	}

	// 출력
	cout << count;

	return 0;
}