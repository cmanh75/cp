#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
int n, l[N];

void solve() {
    cin >> n;
    vector < int > s;
    for (int i = 1; i * i <= n; i++) {
        s.push_back(i * i);
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (l[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            if (!l[j]) {
                l[j] = i;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i, ok = 0;
        while (l[x]) {
            int u = l[x];
            x /= l[x];
            if (x % u == 0) {
                ok = 1;
                break;
            }
        }
        if (!ok) {
            int u = upper_bound(s.begin(), s.end(), n / i) - s.begin();
            ans += 1ll * (u - 1) * (u - 2) * u / 6;
        }
    }
    cout << ans;
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