//problem "1083E-CF"
//created in 09:18:02 - Fri 27/09/2024
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1e6 + 5;

int n;
long long dp[N];
pair < pair < int, int >, int > a[N];

struct line {
    int x;
    long long y;
    long long get(int a) {
        return 1ll * a * x + y;
    }
    bool bad_line(line a, line b) {
        return 1.0 * (y - a.y) / (a.x - x) >= 1.0 * (b.y - a.y) / (a.x - b.x);
    }
};

struct cht {
    vector < line > s;
    void add(line a) {
        while (s.size() > 1 && a.bad_line(s[s.size() - 2], s.back())) {
            s.pop_back();
        }
        s.push_back(a);
    }
    long long bs(int a) {
        int l = 0, r = s.size() - 2, ans = s.back().get(a);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (s[mid].get(a) <= s[mid + 1].get(a)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = s[mid].get(a);
            }
        }
        return ans;
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    cht w;
    w.add({0, 0});
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = w.bs(a[i].fi.se) + a[i].fi.fi * a[i].fi.se - a[i].se;
        w.add({-a[i].fi.fi, dp[i]});
        ans = max(ans, dp[i]);
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