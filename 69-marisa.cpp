//problem "69-marisa"
//created in 15:47:22 - Mon 04/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;
long long s[N], a[N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        s[l]++;
        s[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        cout << s[i] << " ";
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
    // cin >> test;
    while (test--) {
        solve();
    }
}