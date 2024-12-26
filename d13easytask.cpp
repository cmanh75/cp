//problem "d13easytask"
//created in 21:25:35 - Wed 13/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int d[1000005], n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long mins = 1e18, ans = -1e18, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (d[i] == 0) {
            ans = max(ans, sum - mins);
            mins = min(mins, sum - a[i]);
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
    d[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (d[i] == 0) {
            for (int j = i * 2; j <= 1000000; j += i) {
                d[j] = 1;
            }
        }
    }
    int test = 1;
    while (test--) {
        solve();
    }
}