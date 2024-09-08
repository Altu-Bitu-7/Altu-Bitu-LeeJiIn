#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getGcd (int a, int b) {
	if (b == 0) {
		return a;
	}
	return getGcd(b, a % b);
}

vector<int> find_m (int n, vector<int> &v) {
	vector<int> res;
	int gcd = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		gcd = getGcd(gcd, v[i] - v[i - 1]);
	}
	for (int i = 2; i <= gcd; i++) {
		if (gcd % i == 0) {
			res.push_back(i);
		}
	}
	return res;
}

int main() {

	// 입력
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 연산
    sort(v.begin(), v.end());
	vector<int> m = find_m(n, v);

	// 출력
	for (int i : m) {
		cout << i << " ";
	}

	return 0;
}