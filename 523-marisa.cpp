//problem "523-marisa"
//created in 18:55:13 - Fri 06/12/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N][N], b[N][N], m, x, y;
vector < int > s;

void solve() {
    cin >> m >> n >> x >> y;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i <= m - x; i++) {
        for (int j = 0; j <= n - y; j++) {
            bool ok = true;
            for (int k = 0; k < x; k++) {
                for (int h = 0; h < y; h++) {
                    if (b[k][h] != a[i + k][j + h]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                cout << "YES" << "\n";
                return;
            }
        }
    }
    cout << "NO";
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