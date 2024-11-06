//problem "572-marisa"
//created in 20:41:19 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N], r[N], t[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> r[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i] = dp[i - 1] + t[i];
            continue;
        }
        dp[i] = min(dp[i - 2] + r[i], dp[i - 1] + t[i]);
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