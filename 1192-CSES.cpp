//problem "1192-CSES"
//created in 16:27:54 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, d[N][N];
char a[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void bfs(int x, int y) {
    queue < pair < int, int > > qu;
    qu.push({x, y});
    d[x][y] = 1;
    while (qu.size()) {
        pair < int, int > z = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int u = z.first + dx[i];
            int v = z.second + dy[i];
            if (u > 0 && u <= m && v > 0 && v <= n && !d[u][v] && a[u][v] == '.') {
                d[u][v] = 1;
                qu.push({u, v});
            }
        }
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '.' && !d[i][j]) {
                bfs(i, j);
                ans++;
            }
        }
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