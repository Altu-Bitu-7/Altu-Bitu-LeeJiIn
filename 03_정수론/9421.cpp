#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000000

using namespace std;

vector<int> getPrimes() {
	vector<int> primes(MAX + 1, 0);
	for (int i = 2; i <= MAX; i++) {
        	primes[i] = i;
    	}

    	for (int i = 2; i * i <= MAX; i++) {
        	if (primes[i] == 0) {
            		continue;
        	}
        	for (int j = i * i; j <= MAX; j += i) {
            		primes[j] = 0;
        	}
    	}

	return primes;
}

vector<int> split_n (vector<int> &primes) {
	vector<int> primeSang(MAX + 1, 1);
	
	for (int i = 3; i <= MAX; i++) {
		if (primes[i] != 0) { // 소수 중에서만 확인
			vector<int> check; // 계산된 합들을 저장
			while (true) {
				int sum = 0;
                		string str_prime = to_string(primes[i]);
				int len = str_prime.size();
				for (int j = 0; j < len; j++) {
					int split_prime = (primes[i] % 10) * (primes[i] % 10);
					sum += split_prime;
					primes[i] /= 10;
				}
				if (sum == 1) {
					primeSang[i] = i;
					break;
				}
				if (find(check.begin(), check.end(), sum) != check.end()) {
                        		primeSang[i] = 0; // 무한 루프에 빠지면 소수상근수가 아님
                        		break;
                    		}
				check.push_back(sum);
                		primes[i] = sum;
			}
		}
	}
	
	return primeSang;
}

int main() {
	// 입력
	int n;
	cin >> n;

	// 연산
	vector<int> primes = getPrimes();
	vector<int> primeSang = split_n(primes);

	// 출력
	for (int i = 3; i <= n; i++) {
		if (primeSang[i] == i) {
			cout << i << "\n";
		}
	}
}