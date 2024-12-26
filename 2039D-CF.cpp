//problem "2039D-CF"
//created in 23:29:44 - Sat 23/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m, greater<int>());
    if (pf[n] >= m) {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[f[i]] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    pf[0] = -1;
    for (int i = 1; i < nmax; i++) {
        sort(ds[i].begin(), ds[i].end());
        ds[i].erase(unique(ds[i].begin(), ds[i].end()), ds[i].end());
        f[i] = 0;
        while (ds[i].size() > f[i] && ds[i][f[i]] == f[i]) {
            f[i]++;
        }
        for (int j = i; j < nmax; j += i) {
            ds[j].push_back(f[i]);
        }
        pf[i] = max(f[i], pf[i - 1]);
    }
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}