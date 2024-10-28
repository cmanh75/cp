//problem "1777C-CF"
//created in 17:44:35 - Thu 17/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], d[N];
vector < int > s[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        d[i] = 0;
    }
    sort(a + 1, a + n + 1);
    int j = 1, z = 0, ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int k : s[a[i]]) {
            if (k > m) {
                break;
            }
            if (!d[k]) {
                z++;
            }
            d[k]++;
        }
        while (z == m) {
            int ok = 1;
            for (int k : s[a[j]]) {
                if (k > m) {
                    break;
                }
                d[k]--;
                if (!d[k]) {
                    ok = 0;
                }
            }
            if (ok) {
                j++;
                continue;
            }
            for (int k : s[a[j]]) {
                if (k > m) {
                    break;
                }
                d[k]++;
            }
            break;
        }
        if (z == m) {
            ans = min(ans, a[i] - a[j]);
        }
    }
    if (ans == 1e9) {
        cout << -1 << "\n";
        return;
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
    for (int i = 1; i <= 1e5; i++) {
        for (int j = i; j <= 1e5; j += i) {
            s[j].push_back(i);
        }
    }
    cin >> test;
    while (test--) {
        solve();
    }
}