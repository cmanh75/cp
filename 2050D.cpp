//problem "2050D"
//created in 23:37:18 - Thu 05/12/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, c[22][22], d[22], f[N][22], k, q, x, dp[22][N], g[22][22];
const int mod = 1e9 + 7;
map < int, vector < int > > s;

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[x].push_back(i);
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << s[x][k - 1] << "\n";
    }
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