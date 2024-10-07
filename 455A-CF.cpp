//problem "455A-CF"
//created in 21:59:06 - Tue 01/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], d[N], b[N], m = 1;
long long dp[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            m++;
            b[m] = a[i];
        }
    }
    dp[0] = 0;
    dp[1] = 1ll * d[a[1]] * a[1];
    for (int i = 2; i <= m; i++) {
        dp[i] = dp[i - 1];
        if (b[i] == b[i - 1] + 1) {
            dp[i] = max(dp[i], dp[i - 2] + 1ll * d[b[i]] * b[i]);
        }
        else {
            dp[i] = max(dp[i], dp[i - 1] + 1ll * d[b[i]] * b[i]);
        }
    }
    cout << dp[m];
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