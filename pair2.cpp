//problem "pair2"
//created in 20:55:28 - Wed 04/12/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int n, dp[N][N];
char a[N][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = (a[1][1] == '*' ? 0 : 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '*' || (i == 1 && j == 1)) {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }        
    }
    cout << dp[n][n];
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