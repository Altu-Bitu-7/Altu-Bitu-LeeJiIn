#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

	// 입력 & 연산
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
            if (pq.size() < n) { // 힙의 크기가 n보다 작을 때 push
                pq.push(num);
            }
            // 힙의 크기가 n이라면
            else if (num > pq.top()) { // 들어오는 숫자가 가장 작은 수보다 크다면
                pq.pop(); // 가장 작은 수 pop
                pq.push(num); // 큰 수 push
            }
		}
	}

	// 출력
	cout << pq.top(); // 최소 힙이므로 힙의 사이즈가 n인 상태에서는 top에 위치한 수가 n번째로 큰 수

	return 0;
}