//problem "cses1620"
//created in 22:19:36 - Wed 13/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, t, a[N];

bool check(long long x) {
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        s += x / a[i];
    }
    return s >= t;
}

void solve() {
    cin >> n >> t;
    int ma = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    long long l = 1, r = 1ll * ma * (t / n + 1), ans;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
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