//problem "475D-CF"
//created in 15:44:39 - Tue 03/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int f[N][20], a[N], n;
map < int, long long > res;

int get(int l, int r) {
    int o = log2(r - l + 1);
    return __gcd(f[l][o], f[r - (1 << o) + 1][o]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][0] = a[i];
    }
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            f[j][i] = __gcd(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int pre = i, u = a[i];
        while (pre <= n) {
            int l = pre + 1, r = n, npre = n + 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                int z = get(i, mid);
                if (z != u) {
                    npre = mid, r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            res[u] += npre - pre;
            pre = npre;
            u = get(i, pre);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << res[x] << "\n";
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