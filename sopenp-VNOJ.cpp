//problem "sopenp-VNOJ"
//created in 10:24:56 - Thu 17/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, l, u, a[N], d[N], f[N], p[N];

void solve() {
    cin >> n >> l >> u;
    vector < int > s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.push_back(a[i]);
    }
    sort(s.begin(), s.end());
    s.resize(distance(s.begin(), unique(s.begin(), s.end())));
    for (int i = 1; i <= n; i++) {
        p[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
    }
    long long ans = 0;
    int j = 1, k = 1, z = 0, e = 0;
    for (int i = 1; i <= n; i++) {
        if (!d[p[i]]) {
            z++;
        }
        d[p[i]]++;
        if (!f[p[i]]) {
            e++;
        }
        f[p[i]]++;
        while (z > u) {
            z -= (d[p[j]] == 1);
            d[p[j++]]--;
        }
        while (e >= l) {
            e -= (f[p[k]] == 1);
            f[p[k++]]--;
        }
        ans += k - j;
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