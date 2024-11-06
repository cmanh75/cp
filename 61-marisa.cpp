//problem "61-marisa"
//created in 14:44:52 - Mon 04/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], d[N], s[N];

void solve() {
    string t;
    cin >> t;
    int n = t.size();
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '0') {
            a[i + 1] = -1;
        }
        else {
            a[i + 1] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    d[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += d[s[i]];
        d[s[i]]++;
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