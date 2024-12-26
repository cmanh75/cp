//problem "67-marisa"
//created in 15:34:46 - Thu 07/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N][N], m, n;
long long c[N][N];

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            c[i][j] = c[i - 1][j] + a[i][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            long long pre = 0, minpre = 0;
            for (int k = 1; k <= n; k++) {
                pre += c[j][k] - c[i - 1][k];
                ans = max(ans, pre - minpre);
                minpre = min(minpre, pre);
            }
        }
    }
    cout << ans;
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