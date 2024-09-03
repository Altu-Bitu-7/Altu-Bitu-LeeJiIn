#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> getNGE (int n, vector<int> &a) {
	vector<int> answer(n);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[s.top()] < a[i]) {
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}
	
	return answer;
}

int main() {
	// 입력
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);	

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 연산
	vector<int> answer = getNGE(n, a);

	// 출력
    for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}