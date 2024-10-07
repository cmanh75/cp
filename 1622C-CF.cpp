//problem "1622C-CF"
//created in 15:32:44 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
long long k, s[N], a[N];

bool check(long long y,int x) {
    return ((1ll * a[1] - y) * (x + 1) + s[n - x] - s[1]) <= k;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    long long res = 1e18;
    for (int i = 0; i <= n - 1; i++) {
        long long l = 0, r = 1e12, ans = -1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(mid, i)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (ans != -1) {
            res = min(res, ans + i);
        }
    }
    cout << res << "\n";
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