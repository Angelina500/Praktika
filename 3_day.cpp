#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k, m;
    cin >> n >> k >> m;
 
    vector<bool> danger(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        danger[a] = true;
    }
 
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long sum = dp[0];
 
    for (int i = 1; i <= n; ++i) {
        if (danger[i]) {
            dp[i] = 0;
        } else {
            dp[i] = sum % MOD;
        }
 
        sum = (sum + dp[i]) % MOD;
        if (i - k >= 0) {
            sum = (sum - dp[i - k] + MOD) % MOD;
        }
    }
 
    cout << dp[n] % MOD << '\n';
    return 0;
}