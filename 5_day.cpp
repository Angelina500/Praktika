#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
 
    vector<vector<int>> dp(N);
 
    for (int i = 0; i < N; ++i) {
        dp[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            int x;
            cin >> x;
 
            if (i == 0) {
                dp[i][j] = x;
            } else if (j == 0) {
                dp[i][j] = x + dp[i - 1][j];
            } else if (j == i) {
                dp[i][j] = x + dp[i - 1][j - 1];
            } else {
                dp[i][j] = x + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
 
    int ans = 0;
    for (int j = 0; j < N; ++j) {
        ans = max(ans, dp[N - 1][j]);
    }
 
    cout << ans << '\n';
 
    return 0;
}