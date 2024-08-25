#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], n;
long long dp[N][5];
string s;
string t = "hard";

int main() {
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> s;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (s[i - 1] == t[j]) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + a[i]);  
            }
            else {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i]);  
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << sum - ans;
}