#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], n;
long long dp[N][5];
string s;
string t = "hard";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cin.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i] * (s[i - 1] == t[j]));
            if (s[i - 1] == t[j]) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
            }
        }
    }
    long long ans = 1e18;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
}