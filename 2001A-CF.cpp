#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, a[N], d[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    int ma = 0;
    for (int i = 1; i <= n; i++) {
        ma = max(ma, d[i]);
        d[i] = 0;
    }
    cout << n - ma << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
	int test;
    cin >> test;
    while (test--) {
        solve();
    }
}