#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, res, ans;
	cin >> a >> b;
	int up = 0;  // 올림수
	int asize = a.size();  // 첫번째 수의 자릿수
	int bsize = b.size();  // 두번째 수의 자릿수
	while(asize > 0 || bsize > 0) {
		int nn1=0;  // 첫번째 수의 자릿수 중 하나(일의 자리부터 시작)
        	if(asize > 0) {
			nn1 = a[--asize] - '0';  // 문자 0 을 빼주면 함수를 쓰지 않고도 문자를 숫자로 바꾸기 가능
        	}
        	int nn2 = 0;
        	if(bsize > 0) {
        		nn2 = b[--bsize] - '0';
        	}
        	int cur = nn1 + nn2 + up;  
        	up = cur / 10; // 올림수 변경
        	cur %= 10;
        	char ccar = cur + '0';  // 문자로 변환
        	res += ccar;
	}
        if(up > 0) { // 올림수가 마지막까지 남아있다면
		res += up + '0';
	}
	for(int i = res.length() - 1; i >= 0; i--) { // 출력
    		cout << res[i];
  	}
}