//problem "324-marisa"
//created in 09:53:57 - Fri 25/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int m, n, ok = 0;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void cal(int x, int y, int k) {
    a[x][y] = k;
    if (ok == 1) {
        return;
    }
    if (k == m * n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
        }
        ok = 1;
    }
    for (int h = 0; h < 8; h++) {
        int u = x + dx[h];
        int v = y + dy[h];
        if (u >= 0 && v >= 0 && u < m && v < n && !a[u][v]) {
            cal(u, v, k + 1);
        }
    }
    a[x][y] = 0;
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ok) {
                break;
            }
            cal(i, j);
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
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}