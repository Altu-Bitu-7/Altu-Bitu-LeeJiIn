#include <iostream>
#include <vector>

using namespace std;

// 알파벳 개수를 세기 위한 함수
vector<int> countAlphabets (string word) {
	vector<int> alphabetCount(26, 0); // 알파벳 26개 빈도 수 카운트
	for (char c : word) {
		alphabetCount[c - 'A']++;
	}
	
	return alphabetCount;
}

// 두 단어가 비슷한지 확인하는 함수
bool isSimilar (string firstWord, string otherWord) {
	vector<int> firstCount = countAlphabets(firstWord);
	vector<int> otherCount = countAlphabets(otherWord);

	int positiveDiff = 0, negativeDiff = 0;
	// 알파벳이 추가된다면 차이는 -1
	// 알파벳이 삭제된다면 차이는 1
	// 알파벳이 바뀐다면 차이는 0

	for (int i = 0; i < 26; i++) {
		int diff = firstCount[i] - otherCount[i];
		if (diff > 0) positiveDiff += diff;
		else negativeDiff -= diff;
	}

	// 한 글자 차이인지 확인
	if (positiveDiff <= 1 && negativeDiff <= 1) {
		return true;
	}
	
	return false;
}

int main() {
	int n, similarCount = 0;
	string firstWord, otherWord;

	// 입력 & 연산
	cin >> n;
	cin >> firstWord;

	for (int i = 1; i < n; i++) {
		cin >> otherWord;

		if (isSimilar(firstWord, otherWord)) {
			similarCount++;
		}
	}

	// 출력
	cout << similarCount << "\n";

	return 0;
}