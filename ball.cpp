//problem "ball"
//created in 22:12:50 - Tue 15/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], b[N], d[N];

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);
    int l = 1, r = n / 2 + 1, ans = 0;
    for (int i = 1; i <= m && l <= n / 2 && r <= n; i++) {
        if (a[i] <= b[l]) {
            continue;
        }
        while (r <= n && b[r] <= a[i]) {
            r++;
        }
        if (r <= n) {
            l++;
            r++;
            ans++;
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