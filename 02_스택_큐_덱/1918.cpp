#include <iostream>
#include <stack>

using namespace std;

int prior (char c) {
	switch (c) {
		case '+' : case '-' : return 1;
		case '*' : case '/' : return 2;
		default : return 0;
	}
}

string post (string mid) {
	string res;
	stack<char> s;

	for (int i = 0; i < mid.size(); i++) {
		char c = mid[i];

		switch (c) {
			case '(' :
				s.push(c);
				break;

			case ')' :
				while (!s.empty() && s.top() != '(') {
					res += s.top();
					s.pop();
				}
				s.pop();
				break;
			
			case '+' : case '-' : case '*' : case '/' :
				while (!s.empty() && prior(s.top()) >= prior(c)) {
					res += s.top();
					s.pop();
				}
				s.push(c);
				break;
			
			default:
				res += c;
		}
	}

	while (!s.empty()) {
		res += s.top();
		s.pop();
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string mid;
	cin >> mid;

	cout << post(mid);

	return 0;
}