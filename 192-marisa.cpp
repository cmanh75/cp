//problem "192-marisa"
//created in 17:21:15 - Thu 28/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, h[N], lca[N][22];
long long d[N];
vector < pair < int, int > > a[N];

void dfs(int i, int pa) {
    for (pair < int, int > j : a[i]) {
        if (j.first != pa) {
            lca[j.first][0] = i;
            h[j.first] = h[i] + 1;
            d[j.first] = d[i] + j.second;
            dfs(j.first, i);
        }
    }
}

int find_lca(int x, int y) {
    if (h[x] < h[y]) {
        swap(x, y);
    }
    for (int i = log2(n); i >= 0; i--) {
        if (h[lca[x][i]] >= h[y]) {
            x = lca[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = log2(n); i >= 0; i--) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return lca[x][0];
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, z));
    }
    dfs(1, 0);
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 1; j <= n; j++) {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int z = find_lca(x, y);
        cout << d[x] + d[y] - d[z] * 2 << "\n";
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