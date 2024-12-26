//problem "2039C-CF"
//created in 22:01:06 - Sat 23/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int h[N], lca[N][22], q, n;
vector < int > a[N];

void dfs(int i, int pa) {
    for (int j : a[i]) {
        if (j != pa) {
            h[j] = h[i] + 1;
            lca[j][0] = i;
            dfs(j, i);
        }
    }
}

int find_lca(int x, int y) {
    if (h[x] < h[y]) {
        swap(x, y);
    }
    for (int j = log2(n); j >= 0; j--) {
        if (h[lca[x][j]] >= h[y]) {
            x = lca[x][j];
        }
    }
    if (x == y) {
        return y;
    }
    for (int i = log2(n); i >= 0; i--) {
        if (lca[x][i] != lca[y][i]) {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return lca[x][0];
}

int find_lcaa(int x, int y) {
    for (int i = log2(n); i >= 0; i--) {
        if (y >= (1 << i)) {
            x = lca[x][i];
            y -= (1 << i);
        }
    }
    return x;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    h[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 1; j <= n; j++) {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
    cout << find_lcaa(2, 3);
    // while (q--) {
    //     int x, y;
    //     cin >> x >> y;
    //     cout << find_lca(x, y) << " ";
    // }
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