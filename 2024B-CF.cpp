//problem "2024B-CF"
//created in 16:21:07 - Sun 20/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int m, n, a[N][N], b[N][N];
int dx[] = {-1, 1};
int dy[] = {1, -1};

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int x = 1, y = 1, k = 0;
    for (int i = 1; i <= m * n; i++) {
        cout << a[x][y] << " ";
        int u = x + dx[k];
        int v = y + dy[k];
        if (u == 0 || v == 0 || u > m || v > n) {
            if (k == 0) {
                if (v <= n) {
                    u = 1;
                }
                else {
                    u = x + 1;
                    v = y;
                }
            }
            else {
                if (u <= m) {
                    v = 1;
                }
                else {
                    v = y + 1;
                    u = x;
                }
            }
            k = 1 - k;
        }
        x = u, y = v;
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