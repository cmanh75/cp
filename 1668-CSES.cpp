//problem "1668-CSES"
//created in 17:08:51 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int ok = 1, f[N], n, m;
vector < int > a[N];

void dfs(int i, int c) {
    f[i] = c;
    for (int j : a[i]) {
        if (!f[j]) {
            dfs(j, 3 - c);
        }
        else {
            if (f[i] == f[j]) {
                ok = 0;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i]) {
            dfs(i, 1);
        }
    }
    if (!ok) {
        cout << "IMPOSSIBLE";
    }
    else {
        for (int i = 1; i <= n; i++) {
            cout << f[i] << " ";
        }
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