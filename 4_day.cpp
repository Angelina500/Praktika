#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
 
        int ans = a * b * c;
 
        for (int x = 0; x <= 5; ++x) {
            for (int y = 0; y <= 5 - x; ++y) {
                for (int z = 0; z <= 5 - x - y; ++z) {
                    ans = max(ans, (a + x) * (b + y) * (c + z));
                }
            }
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}