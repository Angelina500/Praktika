#include <bits/stdc++.h>
using namespace std;
 
int n, k;
vector<int> a;
int ans = 0;
 
void dfs(int pos, int cnt, int cur_xor) {
    if (cnt == k) {
        ans = max(ans, cur_xor);
        return;
    }
    if (pos == n) return;
    if (n - pos + cnt < k) return;
 
    dfs(pos + 1, cnt, cur_xor);
    dfs(pos + 1, cnt + 1, cur_xor ^ a[pos]);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
 
    dfs(0, 0, 0);
    cout << ans << '\n';
    return 0;
}