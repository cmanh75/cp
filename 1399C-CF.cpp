//problem "1399C-CF"
//created in 15:49:42 - Fri 11/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], d[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum = a[i] + a[j];
            int cnt = 0;
            for (int x = 1; x <= n; x++) {
                if (sum - a[x] >= 0) {
                    if (d[sum - a[x]] > 0) {
                        cnt++;
                        d[sum - a[x]]--;
                    }
                    else {
                        d[a[x]]++;
                    }
                }
            }
            for (int k = 1; k <= n; k++) {
                d[k] = 0;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}