//problem "87-marisa"
//created in 20:50:44 - Mon 25/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], k;

bool check(long long x) {
    long long sum = 0;
    int d = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) {
            return false;
        }
        if (sum + a[i] > x) {
            d++;
            sum = a[i];
        }
        else {
            sum += a[i];
        }
    }
    return (d <= k);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long l = 1, r = 1e14, ans;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid, r = mid - 1;
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