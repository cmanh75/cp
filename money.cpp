#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
int n, a[N], d[N];
long long t;
void solve() {
    cin >> n >> t;
    int mi = 1e9, u = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        u = __gcd(u, a[i]);
    }
    t = t / u;
    for (int i = 1; i <= n; i++) {
        a[i] /= u;
        if (a[i] == 0) {
            continue;
        }
        mi = min(mi, a[i]);
    }
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > pq;
    for (int i = 1; i < mi; i++) {
        d[i] = 1e9;
    }
    pq.push({0, d[0]});
    while (pq.size()) {
        pair < int ,int > x = pq.top();
        pq.pop();
        if (x.first != d[x.second]) {
            continue;
        }
        // cout << x.first << " " << x.second << "\n";
        for (int i = 1; i <= n; i++) {
            if (d[(x.second + a[i]) % mi] > x.first + a[i]) {
                d[(x.second + a[i]) % mi] = x.first + a[i];
                pq.push({d[(x.second + a[i]) % mi], (x.second + a[i]) % mi});
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < mi; i++) {
        mx = max(mx, d[i]);
    }
    if (t > mx) {
        int ans = 0;
        for (int i = 0; i < mi; i++) {
            ans += (mx - d[i]) / mi + 1;
        }
        cout << (t - mx) + ans;
    }
    else {
        int ans = 0;
        for (int i = 0; i <= t; i++) {
            ans += (t - d[i]) / mi + 1;
        }
        cout << ans;
    }
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