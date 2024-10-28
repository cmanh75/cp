//problem "788A-CF"
//created in 14:33:53 - Thu 17/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    for (int i = 2; i <= n; i++) {
        b[i - 1] = abs(a[i] - a[i - 1]) * (i % 2 != 0 ? 1 : -1);
    }
    long long mi1 = 0, mi2 = 0, ans = 0, s = 0;
    for (int i = 1; i < n; i++) {
        s += b[i];
        ans = max({ans, s - mi1, mi2 - s});
        if (b[i] > 0) {
            mi2 = max(mi2, s);
        }
        else {
            mi1 = min(mi1, s);
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
    int test = 1;
    while (test--) {
        solve();
    }
}