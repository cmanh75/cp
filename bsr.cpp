//problem "bsr"
//created in 16:54:14 - Fri 06/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
int a[N][N], s[N][N], d[N], m, n;

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s[i][j] = (s[i][j - 1] + a[i][j]) % 9;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= n; k++) {
                d[k] = 0;
            }
            d[0] = 1;
            int t = 0;
            for (int k = 1; k <= m; k++) {
                t = (t + s[k][i] - s[k][j - 1]) % 9;
                ans += d[t];
                d[t]++;
            }
        }
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