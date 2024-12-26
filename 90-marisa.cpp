//problem "90-marisa"
//created in 22:30:42 - Mon 25/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
double a[N], b[N], s[N];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - x;
        s[i] = s[i - 1] + b[i];
    }
    double mi = 0;
    for (int i = k; i <= n; i++) {
        mi = min(mi, s[i - k]);
        if (s[i] - mi >= 0) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double l = 1, r = 1e9, ans;
    while (l <= r) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid, l = mid + 1e-5;
        }
        else {
            r = mid - 1e-5;
        }
    }
    cout << setprecision(3) << fixed << ans;
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