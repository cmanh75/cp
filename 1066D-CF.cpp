//problem "1066D-CF"
//created in 15:09:02 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, a[N];

bool check(int x) {
    int sz = k, w = m - 1;
    for (int i = x + 1; i <= n; i++) {
        if (sz >= a[i]) {
            sz -= a[i];
        }
        else {
            sz = k - a[i];
            w--;
            if (w < 0) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << n - ans;
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