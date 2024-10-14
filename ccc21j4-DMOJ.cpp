//problem "ccc21j4-DMOJ"
//created in 22:35:16 - Sat 12/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

void solve() {
    string s;
    cin >> s;
    int j = 0, l = 0, m = 0;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        l += (s[i] == 'L');
        m += (s[i] == 'M');
    }
    for (int i = l, j = 0; i < l + m && j < l; i++) {
        if (s[i] == 'L') {
            while (j < l && s[j] != 'M') {
                j++;
            }
            if (j < l) {
                ans++;
                swap(s[i], s[j]);
            }
        }
    }
    for (int i = l + m, j = 0; i < n && j < l; i++) {
        if (s[i] == 'L') {
            while (j < l && s[j] != 'S') {
                j++;
            }
            if (j < l) {
                ans++;
                swap(s[i], s[j]);
            }
        }
    }
    for (int i = l, j = 0; i < n && j < l; i++) {
        if (s[i] == 'L') {
            while (j < l && s[j] == 'L') {
                j++;
            }
            if (j < l) {
                ans++;
                swap(s[i], s[j]);
            }
        }
    }
    for (int i = l; i < l + m; i++) {
        ans += (s[i] != 'M');
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test = 1;
    while (test--) {
        solve();
    }
}