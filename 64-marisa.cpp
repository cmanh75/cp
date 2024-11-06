//problem "64-marisa"
//created in 11:30:54 - Sun 03/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, w[N][N], m, q;
long long s[N][N];

void solve() {
    cin >> m >> n >> q;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + w[i][j];
        }
    }
    for (int i = 1; i <= q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1] << "\n";
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