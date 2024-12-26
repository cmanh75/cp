//problem "bao1"
//created in 13:44:20 - Sat 30/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, f[N][22], b[N];
pair < int, int > a[N];

int get_max(int x, int y) {
    if (x > y) {
        return -1e9;
    }
    int o = log2(y - x + 1);
    return max(f[x][o], f[y - (1 << o) + 1][o]);
}

bool check(long long x) {
    for (int i = 1; i <= n; i++) {
        long long z = (x + a[i].first - 1) / a[i].first;
        long long w = (x + a[i].second - 1) / a[i].second;
        int u = lower_bound(b + 1, b + n + 1, z) - b;
        if (get_max(u, i - 1) >= w) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        f[i][0] = a[i].second;
    }
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[i].first;
    }
    long long l = 1, r = 1e18, ans;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
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