//problem "580C-CF"
//created in 17:29:55 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, c[N], ans = 0;
vector < int > a[N];

void dfs(int i, int pa, int d) {
    if (a[i].size() == 1 && i != 1) {
        ans++;
    }
    for (int j : a[i]) {
        if (j != pa && (c[j] == 0 ? 0 : d + 1) <= m) {
            dfs(j, i, (c[j] == 0 ? 0 : d + 1));
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0, c[1]);
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