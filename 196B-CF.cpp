//problem "196B-CF"
//created in 16:09:43 - Sun 15/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
int m, n, d[N][N];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
char a[N][N];

void solve() {
    cin >> m >> n;
    queue < pair < int, int > > qu;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                qu.push({i + m, j + n});
            }
        }
    }
    for (int i = 0; i < m * 3; i++) {
        for (int j = 0; j < n * 3; j++) {
            a[i][j] = a[i % m][j % n];
        }
    }
    while (qu.size()) {
        pair < int, int > z = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int u = z.first + dx[i];
            int v = z.second + dy[i];
            if (u >= 0 && v >= 0 && u < 3 * m && v < 3 * n && a[u][v] != '#' && !d[u][v]) {
                d[u][v] = 1;
                qu.push({u, v});
            }
        }
    }
    for (int i = 0; i < 3 * m; i++) {
        if (d[i][0] || d[i][n * 3 - 1]) {
            cout << "YES" << "\n";
            return;
        }
    }
    for (int i = 0; i < 3 * n; i++) {
        if (d[0][i] || d[m * 3 - 1][0]) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
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