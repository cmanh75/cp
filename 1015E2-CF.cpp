#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, r[N][N], c[N][N], m, g[N][N], f[N][N];
char a[N][N];

struct iii {
    int x, y, z;
};

vector < iii > res;

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            r[i][j] = r[i][j - 1] + (a[i][j] == '*');
            c[i][j] = c[i - 1][j] + (a[i][j] == '*');
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int le = 1, ri = min(min(n - j, j - 1), min(m - i, i - 1)), ans = 0;
            while (le <= ri) {
                int mid = (le + ri) / 2;
                if ((r[i][j + mid] - r[i][j - mid - 1] == 2 * mid + 1) && (c[i + mid][j] - c[i - mid - 1][j] == 2 * mid + 1)) {
                    ans = mid, le = mid + 1;
                }
                else {
                    ri = mid - 1;
                }
            }
            if (ans != 0) {
                f[i][j - ans]++;
                f[i][j + ans + 1]--;
                g[i - ans][j]++;
                g[i + ans + 1][j]--;
                res.push_back({i, j, ans});
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] += f[i][j - 1];
            g[i][j] += g[i - 1][j];
            if (a[i][j] == '*' && g[i][j] + f[i][j] == 0) {
                cout << -1;
                return;
            }
        }
    }
    cout << res.size() << "\n";
    for (auto [x, y, z] : res) {
        cout << x << " " << y << " " << z << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
	  int test = 1;
    while (test--) {
        solve();
    }
}