//problem "1193-CSES"
//created in 16:39:24 - Thu 10/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int m, n, d[N][N], tr[N][N];
char a[N][N];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
string Move = "ULRD";

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
            if (u > 0 && u <= m && v > 0 && v <= n && !d[u][v] && a[u][v] != '#') {
                d[u][v] = d[z.first][z.second] + 1;
                tr[u][v] = i;
                qu.push({u, v});
            }
        }
    }
}

void solve() {
    int sx, sy, ex, ey;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                sx = i, sy = j;
            }
            if (a[i][j] == 'B') {
                ex = i, ey = j;
            }
        }
    }
    bfs(sx, sy);
    if (!d[ex][ey]) {
        cout << "NO";
        return;
    }
    vector < char > ans;
    cout << "YES" << "\n";
    cout << d[ex][ey] - 1 << "\n";
    while (ex != sx || ey != sy) {
        int u = tr[ex][ey];
        ex -= dx[u];
        ey -= dy[u];
        ans.push_back(Move[u]);
    }
    reverse(ans.begin(), ans.end());
    for (char c : ans) {
        cout << c;
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