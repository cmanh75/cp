//problem "c3-fc"
//created in 21:04:04 - Mon 07/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, k, a[N], d[N];

void solve() {
    cin >> n >> k;
    if (k > 1000000) {
        cout << 0;
        return;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int j = 1; j <= n; j++) {
        if (k - a[j] * a[j] >= 0) {
            ans += d[k - a[j] * a[j]];
        }
        d[a[j]]++;
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