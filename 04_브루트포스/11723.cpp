#include <iostream>

using namespace std;

void all (int &s) {
	s = (1 << 21) - 1;
}

void empty (int &s) {
	s = 0;
}

void add (int &s, int n) {
	s |= (1 << n);
}

void remove (int &s, int n) {
	s &= ~(1 << n);
}

int check (int &s, int n) {
	if (s & (1 << n)) {
		return 1;
	}
	else {
		return 0;
	}
}

void toggle (int &s, int n) {
	s ^= (1 << n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, x, s = 0;
	string op;
	cin >> m;
	while (m--) {
		cin >> op;

		// x 피연산자가 입력되지 않는 연산자
		if (op == "all") {
			all(s);
		}
		else if (op == "empty") {
			empty(s);
		}

		// x 피연산자가 입력되는 연산자
		else {
			cin >> x;
			if (op == "add") {
				add(s, x);
			}
			else if (op == "remove") {
				remove(s, x);
			}
			else if (op == "check") {
				cout << check(s, x) << "\n";
			}
			else if (op == "toggle") {
				toggle(s, x);
            }
		}
	}	
	
	return 0;
}