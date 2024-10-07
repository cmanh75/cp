//problem "height-fc"
//created in 20:36:39 - Mon 07/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N], m;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
        int l = 1, r = n, ans = n + 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] > b[i]) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans - 1 << " ";
    }
    
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