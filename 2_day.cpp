#include <bits/stdc++.h>
using namespace std;
 
vector<int> prefix_function(const string& s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s, t;
    cin >> s >> t;
 
    int n = (int)s.size();
    if ((int)t.size() != n) {
        cout << -1 << '\n';
        return 0;
    }
 
    string doubled = s + s;
    vector<int> pi = prefix_function(t);
 
    int j = 0;
    int best_pos = -1;
 
    for (int i = 0; i < (int)doubled.size(); ++i) {
        while (j > 0 && doubled[i] != t[j]) j = pi[j - 1];
        if (doubled[i] == t[j]) ++j;
 
        if (j == n) {
            int pos = i - n + 1;
            best_pos = max(best_pos, pos);
            j = pi[j - 1];
        }
    }
 
    if (best_pos == -1) {
        cout << -1 << '\n';
    } else {
        cout << (n - best_pos) % n << '\n';
    }
 
    return 0;
}