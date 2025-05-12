//problem "hieu"
//created in 09:21:29 - Wed 23/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, f[N], a[N], b[N], k1, k2;

void solve() {
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    while (k1 > 0) {
        int ans = -1, cs;
        for (int i = 1; i <= n; i++) {
            if (ans < abs(a[i] - b[i])) {
                ans = abs(a[i] - b[i]);
                cs = i;
            }
        }
        if (a[cs] < b[cs]) {
            a[cs]++;
        }
        else {
            a[cs]--;
        }
        k1--;
    }
    while (k2 > 0) {
        int ans = -1, cs;
        for (int i = 1; i <= n; i++) {
            if (ans < abs(a[i] - b[i])) {
                ans = abs(a[i] - b[i]);
                cs = i;
            }
        }
        if (a[cs] < b[cs]) {
            b[cs]--;
        }
        else {
            b[cs]++;
        }
        k2--;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * (b[i] - a[i]) * (b[i] - a[i]);
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