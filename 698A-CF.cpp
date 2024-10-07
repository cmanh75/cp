//problem "698A-CF"
//created in 22:20:41 - Wed 02/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], dp[N][4], n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[1][0] = 1;
    if (a[1] == 2 || a[1] == 3) {
        dp[1][2] = 0;
    }
    if (a[1] == 1 || a[1] == 3) {
        dp[1][1] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][0] = min(dp[i - 1][j] + 1, dp[i][0]);
        }
        if (a[i] == 2 || a[i] == 3) {
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
        }
        if (a[i] == 1 || a[i] == 3) {
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]});
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