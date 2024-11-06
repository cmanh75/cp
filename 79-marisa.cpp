//problem "79-marisa"
//created in 21:17:42 - Mon 28/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long s[N];
pair < int, int > a[N];

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i].second;
    }
    while (q--) {
        long long x;
        cin >> x;
        int u = lower_bound(s + 1, s + n + 1, x) - s;
        cout << a[u].first << "\n";
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