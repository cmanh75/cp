//problem "95-marisa"
//created in 21:32:11 - Mon 11/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], f[N], k;

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
        f[i] = max(f[i - 1], i - j + 1);
    }
    j = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while (a[i] - a[j] > k) {
            j++;
        }
        ans = max(ans, i - j + 1 + f[j - 1]);
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