//problem "56E-CF"
//created in 18:12:42 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, f[N], b[N], ans[N];
pair < int, int > a[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

struct bit{
    int f[N];
    void update(int x, int val) {
        for (; x <= n; x += (x & -x)) {
            f[x] = max(f[x], val);
        }
    }
    int get(int x) {
        int ans = 0;
        for (; x != 0; x -= (x & -x)) {
            ans = max(ans, f[x]);
        }
        return ans;
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        b[i] = i;
        cin >> a[i].first >> a[i].second;
    }
    sort(b + 1, b + n + 1, cmp);
    sort(a + 1, a + n + 1);
    bit w;
    for (int i = n; i > 0; i--) {
        ans[b[i]] = i;
        int u = lower_bound(a + 1, a + n + 1, make_pair(a[i].first + a[i].second, 0)) - a - 1;
        ans[b[i]] = max(ans[b[i]], w.get(u));
        w.update(i, ans[b[i]]);
        ans[b[i]] = ans[b[i]] - i + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
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