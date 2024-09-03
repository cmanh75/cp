//problem "2000G-CF"
//created in 16:30:11 - Wed 28/08/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
struct iii{
    int v, l1, l2;
};
int t1, t2, t0, n, m, d[N];
vector < iii > s[N];

void solve() {
    cin >> n >> m >> t0 >> t1 >> t2;
    for (int i = 1; i <= n; i++) {
        s[i].clear();
        d[i] = -1e9;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, l1, l2;
        cin >> x >> y >> l1 >> l2;
        s[x].push_back({y, l1, l2});
        s[y].push_back({x, l1, l2});
    }
    priority_queue < pair < int, int > > pq;
    d[n] = t0;
    pq.push({t0, n});
    while (pq.size()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != d[u]) {
            continue;
        }
        for (auto [v, l1, l2] : s[u]) {
            int dv;
            if (du - l1 >= t2 || du <= t1) {
                dv = du - l1;
            }
            else {
                dv = max(du - l2, t1 - l1);
            }
            if (dv > d[v]) {
                d[v] = dv;
                pq.push({d[v], v});
            }
        }
    }
    if (d[1] < 0) {
        cout << -1 << "\n";
        return;
    }
    cout << d[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}