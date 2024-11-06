//problem "140-marisa"
//created in 20:09:10 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int dp[N];

void solve() {
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (i >= 2) {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
        if (i >= 3) {
            dp[i] = (dp[i] + dp[i - 3]) % mod;
        }
    }
    cout << dp[n];
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