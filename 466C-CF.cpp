//problem "466C-CF"
//created in 12:09:54 - Mon 30/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, a[N], f[N];

void solve() {
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << 0;
        return;
    }
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        cur += a[i];
        if (cur == sum / 3) {
            f[i]++;
        }
    }
    cur = 0;
    long long ans = 0;
    for (int i = n; i >= 3; i--) {
        cur += a[i];
        if (cur == sum / 3) {
            ans += f[i - 2];
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