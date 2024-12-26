//problem "2034A-CF"
//created in 21:38:31 - Sat 30/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char a[N][N];
int m, n, d[N][N], f[N][N];

bool dfs(int i, int j) {
    d[i][j] = 1;
    if (i == 0 || j == 0 || i == m + 1 || j == n + 1) {
        return f[i][j] = 1;
    }
    if (a[i][j] == '?') {
        return f[i][j] = 0;
    }
    int &ans = f[i][j];
    if (a[i][j] == 'L') {
        j--;
    }
    else if (a[i][j] == 'R') {
        j++;
    }
    else if (a[i][j] == 'U') {
        i--;
    }
    else if (a[i][j] == 'D') {
        i++;
    }
    if (!d[i][j]) {
        dfs(i, j);
    } 
    ans = f[i][j];
    return f[i][j];
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (m == 1 && n == 1) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i <= m + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            d[i][j] = f[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i == 1 || j == 1 || i == m || j == n ) && !d[i][j]) {
                dfs(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            ans += f[i][j];
            if (a[i][j] == '?' && d[i][j] == 0) {
                ans++;
            }
        }
    }
    cout << m * n - ans << "\n";
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