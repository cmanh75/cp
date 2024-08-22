#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, a[N], d[N], l[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mi = 0, ma = 0, ans;
    for (int i = 1; i <= n; i++) {
        if (d[a[i]]) {
            l[d[a[i]]]--;
            if (!l[d[a[i]]] && mi == d[a[i]]) {
                mi++;
            }
        }
        else {
            mi = 1;
        }
        d[a[i]]++;
        l[d[a[i]]]++;
        if (l[d[a[i]]] == 1) {
            ma = max(ma, d[a[i]]);
        }
        if (ma == mi && (l[ma] == 1 || l[ma] == i)) {
            ans = i;
        }
        if (ma == mi + 1 && l[ma] == 1) {
            ans = i;
        }
        if (mi == 1 && ma * l[ma] + 1 == i) {
            ans = i;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
	int test = 1;
    while (test--) {
        solve();
    }
}