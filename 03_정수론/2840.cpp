#include <iostream>
#include <vector>

using namespace std;

void setWheel (vector<char> &wheel) {
	for (int i = 0; i < wheel.size(); i++) {
		wheel[i] = '?';
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<char> wheel(n);
	setWheel(wheel);

	int cnt, idx = 0;
	char alphabet;
	for (int i = 0; i < k; i++) {
		cin >> cnt >> alphabet;
		if (i == 0) {
			wheel[0] = alphabet;
			continue;
		}
		idx = (cnt + idx) % n;
		if (wheel[idx] != '?' && wheel[idx] != alphabet) {
			cout << '!';
			return 0;
		}
		else {
			wheel[idx] = alphabet;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (wheel[i] != '?' && wheel[i] == wheel[j]) {
				cout << '!';
				return 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << wheel[idx--];
		if (idx == -1) {
			idx = n - 1;
		}
	}
	
	return 0;
}