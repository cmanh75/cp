//problem "442-marisa"
//created in 14:04:16 - Thu 07/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
long long dp[7][N], s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int j = 1; j <= 6; j++) {
        for (int i = 0; i <= n; i++) {
            dp[j][i] = -1e18;
        }
    }
    for (int j = 1; j <= 6; j++) {
        if (j % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = max(dp[j][i - 1], dp[j - 1][i] + s[i]);
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = max(dp[j][i - 1], dp[j - 1][i - 1] - s[i - 1]);
            }
        }
    }
    cout << dp[6][n];
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