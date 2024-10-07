//problem "backtracking"
//created in 10:14:51 - Sun 29/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, x[N], a[N];
long long ans = 1e18;

void cal(int i) {
    if (i > n) {
        long long sum = 0, all = 0;
        for (int j = 1; j <= n; j++) {
            sum += 1ll * x[j] * a[j];
            all += a[j];
        }
        ans = min(ans, abs(sum - (all - sum)));
        return;
    }
    x[i] = 1;
    cal(i + 1);
    x[i] = 0;
    cal(i + 1);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cal(1);
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