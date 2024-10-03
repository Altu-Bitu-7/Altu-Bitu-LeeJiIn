#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards; // 0: 도도, 1: 수연

// 승리 판단하기
string judge (cards deck) {
	int do_deck = deck[0].size(), su_deck = deck[1].size();
	if (do_deck > su_deck) {
		return "do";
	}
	else if (do_deck < su_deck) {
		return "su";
	}
	return "dosu";
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck (deque<int> &deck, deque<int> &ground) {
	while (!ground.empty()) {
		deck.push_back(ground.back());
		ground.pop_back();
	}
}

// 종을 쳤을 때
void ringTheBell (int player, cards &deck, cards &ground) {
	groundToDeck(deck[player], ground[!player]); // 상대 그라운드 -> 본인 덱
	groundToDeck(deck[player], ground[player]); // 본인 그라운드 -> 본인 덱
}

// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell (cards ground) {
	if ((!ground[0].empty() && ground[0].front() == 5) || (!ground[1].empty() && ground[1].front() == 5)) { // 도도
		return 0;
	}
	else if (!ground[0].empty() && !ground[1].empty() && (ground[0].front() + ground[1].front() == 5)) { // 수연
		return 1;
	}
	return -1; // 종을 울릴 수 없음
}

string game (int m, cards &deck, cards &ground) {
	bool turn = 0; // 도도 먼저
	while (m--) {
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기
		deck[turn].pop_front();
		if (deck[turn].empty()) {
			break;
		}

		int bell = whoCanRingTheBell(ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);
		}
		turn = !turn; // 차례 바꾸기
	}

	return judge(deck);
}

/*
도도, 수연이 각각 덱과 그라운드를 가짐
도도->수연->도도->수연... 순서로 게임 진행 (game 함수)
1. 카드를 덱에서 한 장 내려놓음
2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
3. 종을 친 경우 그라운드의 카드를 덱으로 이동 (ringTheBell, groundToDeck 함수)
종료 조건 만족 시 승리한 사람 리턴 (judge 함수)
*/

int main() {
	int n, m, card1, card2;
	cards deck(2), ground(2);

	// 입력
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2;
		deck[0].push_front(card1);
		deck[1].push_front(card2);
	}

	// 출력 & 연산
	cout << game(m, deck, ground);

	return 0;
}