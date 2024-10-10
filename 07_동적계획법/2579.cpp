#include <iostream>
#include <vector>

using namespace std;

int maxScore (vector<int> num, int n) {
    if (n == 1) {
        return num[0]; // 계단이 하나일 경우
    }
    else if (n == 2) {
        return num[0] + num[1]; // 계단이 두개일 경우
    }
    else { // 계단이 세개 이상일 경우
        vector<int> dp(n); // 각 계단까지의 최대 점수 저장
        dp[0] = num[0];
        dp[1] = num[0] + num[1];
        dp[2] = max(num[0] + num[2], num[1] + num[2]);
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 2] + num[i], dp[i - 3] + num[i - 1] + num[i]);
        }
        return dp[n - 1];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << maxScore(num, n);

    return 0;
}