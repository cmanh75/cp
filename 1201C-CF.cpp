//problem "1201C-CF"
//created in 12:50:43 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], n, k;

bool check(long long x) {
    long long z = k;
    for (int i = n / 2 + 1; i <= n; i++) {
        if (x >= a[i]) {
            z -= x - a[i];
        }
    }
    return (z >= 0);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long l = a[n / 2 + 1], r = 2e9, ans;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (!check(mid)) {
            r = mid - 1;
        }
        else {
            ans = mid;
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