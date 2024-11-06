//problem "575-marisa"
//created in 22:04:12 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, b[N];
long long dp[N], pre[N];
pair < int, int > a[N];

bool cmp(pair < int, int > a, pair < int, int > b) {
    return a.second < b.second;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i].second;
    }
    for (int i = 1; i <= n; i++) {
        int u = lower_bound(b + 1, b + n + 1, a[i].first) - b - 1;
        dp[i] = pre[u] + a[i].second - a[i].first + 1;
        pre[i] = max(pre[i - 1], dp[i]);
    }
    cout << pre[n];
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