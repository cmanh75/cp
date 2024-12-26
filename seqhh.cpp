//problem "seqhh"
//created in 20:51:02 - Wed 27/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], k, s[N];
map < int, int > d;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        ans += d[s[i] - k];
        d[s[i]]++;
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