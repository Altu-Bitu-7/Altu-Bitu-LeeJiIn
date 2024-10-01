#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}