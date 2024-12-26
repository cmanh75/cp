//problem "missingnum"
//created in 21:16:52 - Mon 18/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N], m, k;

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int j = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        while (j <= m && a[i] - k > b[j]) {
            j++;
        }
        if (j <= m && b[j] >= a[i] - k && b[j] <= a[i] + k) {
            ans++;
            j++;
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