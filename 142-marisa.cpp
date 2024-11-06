//problem "142-marisa"
//created in 21:38:24 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, k, dp[N], s[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        if (i > k) {
            dp[i] = (dp[i] + s[i - k]) % mod;
        } 
        s[i] = (s[i - 1] + dp[i]) % mod;
    }
    cout << s[n] + 1;
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