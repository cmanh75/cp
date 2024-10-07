//problem "1085-CSES"
//created in 21:24:04 - Mon 07/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], n, k;

bool check(long long x) {
    int z = 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) {
            return false;
        }
        if (sum + a[i] > x) {
            sum = a[i];
            z++;
        }
        else {
            sum += a[i];
        }
    }
    return (z <= k);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long l = 1, r = 2e14, ans;
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