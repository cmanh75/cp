//problem "ccc18s2-DMOJ"
//created in 10:54:16 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int a[N][N], n, b[N][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                b[k][n - j + 1] = a[j][k];
            }
        }
        int ok = 1;
        for (int i = 2; i <= n; i++) {
            if (b[i][1] < b[i - 1][1]) {
                ok = 0;
            }
            if (b[1][i] < b[1][i - 1]) {
                ok = 0;
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                a[j][k] = b[j][k];
            }
        }
        if (ok == 1) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    cout << a[j][k] << " ";
                }
                cout << "\n";
            }
            return;
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