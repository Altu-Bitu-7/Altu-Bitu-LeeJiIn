#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, a, gift;
	priority_queue<int> pq;

	// 입력 & 연산 & 출력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) { // 입력한 수가 0이라면
			if (pq.empty()) { // 힙이 비었다면
				cout << "-1\n"; // -1 출력
			}
			else { // 힙이 비어있지 않다면
				cout << pq.top() << "\n"; // 가장 가치 있는 선물 pop
				pq.pop();
			}
		}
		else { // 입력한 수가 0이 아니라면
			while (a--) {
				cin >> gift;
				pq.push(gift); // 힙에 선물들 push
			}
		}
	}
	
	return 0;
}