//problem "643-USACO"
//created in 10:16:30 - Thu 17/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], k, f[N], l[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int j = 1;
    for (int i = 1; i <= n; i++) {
        while (a[i] - a[j] > k) {
            j++;
        }
        f[i] = i - j + 1;
        l[i] = max(l[i - 1], f[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] + l[i - f[i]]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "diamond"
    if(fopen(task ".in", "r")) {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test = 1;
    while (test--) {
        solve();
    }
}