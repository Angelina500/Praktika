#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
 
        int ans = n * a;
        for (int x = 0; x <= n / 2; ++x) {
            ans = min(ans, x * b + (n - 2 * x) * a);
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}
