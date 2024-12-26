//problem "73-marisa"
//created in 15:28:14 - Thu 07/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
int n, a[N][N];
long long g[N][N], f[N][N], k, m;

long long get_f(int x, int y) {
    return f[x][y] - f[x - k - 1][y - k - 1];
}

long long get_g(int x, int y) {
    return g[x][y] - g[x - k - 1][y + k + 1];
}

void solve() {
    cin >> n >> k;
    int m = k + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i + m][j + m];
        }
    }
    for (int i = 1; i <= n + 2 * m; i++) {
        for (int j = 1; j <= n + m * 2; j++) {
            f[i][j] = f[i - 1][j - 1] + a[i][j];
            g[i][j] = g[i - 1][j + 1] + a[i][j];
        }
    }
    long long sum = 0;
    for (int i = m + 1; i <= m + k + 1; i++) {
        for (int j = m + 1; j <= m + k + 1; j++) {
            if (abs(i - m - 1) + abs(j - m - 1) <= k) {
                sum += a[i][j];
            }
        }
    }
    for (int i = m + 1; i <= n + m; i++) {
        long long sumc = sum;
        for (int j = m + 1; j <= m + n; j++) {
            cout << sumc << " ";
            sumc += get_f(i, j + k + 1) + get_g(i + k, j + 1) - a[i][j + k + 1];
            sumc -= get_f(i + k, j) + get_g(i, j - k) - a[i][j - k];
        }
        sum -= get_g(i, m + 1 - k) + get_f(i, m + 1 + k) - a[i - k][m + 1];
        sum += get_g(i + k + 1, 1 + m) + get_f(i + k + 1, 1 + m) - a[i + k + 1][m + 1];
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