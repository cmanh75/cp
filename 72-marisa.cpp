//problem "72-marisa"
//created in 16:05:11 - Mon 04/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int m, n, q, f[N][N];

void solve() {
    cin >> m >> n >> q;
    for (int i = 1; i <= q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        f[a][b]++;
        f[a][d + 1]--;
        f[c + 1][b]--;
        f[c + 1][d + 1]++;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
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