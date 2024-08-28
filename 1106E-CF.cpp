//problem "1106E-CF"
//created in 16:18:32 - Tue 27/08/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, k;
pair < int, int > it[N * 4];
long long dp[N][205];

void update(int i, int l, int r, int le, int ri, pair < int, int > val) {
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        it[i] = max(it[i], val);
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, le, ri, val);
    update(i * 2 + 1, mid + 1, r, le, ri, val);
}

pair < int, int > get(int i, int l, int r, int p) {
    if (l == r) {
        return it[i];
    }
    int mid = (l + r) / 2;
    if (mid >= p) {
        return max(it[i], get(i * 2, l, mid, p));
    }
    return max(it[i], get(i * 2 + 1, mid + 1, r, p));
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x, y, z, w;
        cin >> x >> y >> w >> z;
        update(1, 1, n, x, y, make_pair(z, w));
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            dp[i][j] = 1e18;
        }
    }
    dp[n + 1][m] = 0;
    for (int i = n; i > 0; i--) {
        pair < int, int > z = get(1, 1, n, i);
        for (int j = 0; j <= m; j++) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
            if (!z.second) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                continue;
            }   
            dp[i][j] = min(dp[i][j], dp[z.second + 1][j] + z.first);
        }
    }
    long long ans = 1e18;
    for (int i = 0; i <= m; i++) {
        ans = min(ans, dp[1][i]);
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