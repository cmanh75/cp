//problem "1715D-CF"
//created in 12:41:24 - Wed 28/08/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[33][N];
vector < int > e[N];

struct edge {
    int x, y, z;
};

vector < edge > s[33];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        for (int j = 0; j < 30; j++) {
            s[j].push_back({x, y, (z >> j & 1)});
        }
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 1;
            e[j].clear();
        }
        for (auto [x, y, z] : s[i]) {
            if (!z) {
                a[i][x] = a[i][y] = 0;
            }
            else {
                e[x].push_back(y);
                e[y].push_back(x);
            }
        }
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) {
                continue;
            }
            int ok = 0;
            for (int k : e[j]) {
                ok |= (a[i][k] == 0 || j == k);
            }
            a[i][j] = ok;
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j = 0; j < 30; j++) {
            x += (a[j][i] * (1 << j));
        }
        cout << x << " ";
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