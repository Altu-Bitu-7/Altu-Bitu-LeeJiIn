#include <iostream>
#include <string>

using namespace std;

string solution (string number, int k) {
	string answer = "";
	int max_idx, max_val = 0, idx = 0;

	while (idx < number.length()) {
		if (max_val < number[idx]) { // 최댓값과 인덱스 갱신
			max_val = number[idx];
			max_idx = idx;
		}
		if (idx == k) { // k: 한번 탐색할 때 k까지 탐색
			// 인덱스 k까지 다 탐색하면, 앞서 탐색한 숫자들 중 최댓값부터 다시 탐색 시작
			// 앞부분을 추가하지 않기 위함
			idx = max_idx;
			k++; // 다음 탐색 범위 확대
			answer.push_back(max_val);
			max_val = 0; // 새로운 최댓값을 찾아야 하므로 최댓값 초기화
		}
		idx++;
	}

	return answer;
}