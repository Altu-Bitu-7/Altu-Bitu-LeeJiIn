#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, result, ans;
	cin >> a >> b;
	int up = 0;  // 올림수

	int asize = a.size();
	int bsize = b.size();
	while (asize > 0 || bsize > 0) {
		int n1_point = 0;  // 첫번째 수의 자릿수 (일의 자리부터 시작)
        	if (asize > 0) {
			n1_point = a[--asize] - '0';
        	}

        	int n2_point = 0;
        	if (bsize > 0) {
        		n2_point = b[--bsize] - '0';
        	}

        	int point_sum = n1_point + n2_point + up;  
        	up = point_sum / 10;
        	point_sum %= 10;
        	result += point_sum + '0';
	}
        if (up > 0) {
		result += up + '0';
	}

	for (int i = result.length() - 1; i >= 0; i--) {
    		cout << result[i];
  	}
}