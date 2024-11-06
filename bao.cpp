//problem "bao"
//created in 08:58:38 - Wed 30/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    int hmin, hmax, wmin, wmax;
    cin >> hmin >> hmax >> wmin >> wmax;
    int ans;
    for (int i = 1; i <= sqrt(max(hmax, wmax)); i++) {
        if (hmax / i > (hmin - 1) / i && wmax / i > (wmin - 1) / i) {
            ans = i;
        }
    }
    int j = 1;
    for (int i = 1; i <= sqrt(hmax); i++) {
        int r = hmax / i;
        int l = (hmin - 1) / i + 1;
        if (l > r) {
            continue;
        }
        int u = (wmin - 1) / j + 1;
        int v = wmax / j;
        while (j < sqrt(wmax) && (u > v || u > r)) {
            j++;
            u = (wmin - 1) / j + 1;
            v = wmax / j;
        }
        if (u <= v) {
            if (r >= u && r <= v) {
                ans = max(ans, r);
            }
            if (v >= l && r >= v) {
                ans = max(ans, v);
            }
        }
    }
    cout << ans << "\n";
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