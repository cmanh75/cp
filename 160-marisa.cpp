//problem "160-marisa"
//created in 21:22:05 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N];
long long dp[N][2][3];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0][1] = max(dp[i - 1][1][1], dp[i - 1][1][2]) + a[i]; 
        dp[i][0][2] = dp[i - 1][0][1] + a[i]; 
        dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 1][0][2]) + b[i]; 
        dp[i][1][2] = dp[i - 1][1][1] + b[i]; 
    }
    long long ans = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 1; j <= 2; j++) {
            ans = max(ans, dp[n][i][j]);
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