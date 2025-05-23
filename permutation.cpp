//problem "permutation"
//created in 20:41:32 - Wed 09/10/2024
#include<bits/stdc++.h>
#define piii pair < long long, pair < int, int > >
using namespace std;

const int N = 1e6 + 5;
int n, a[N];

void solve() {
    cin >> n;
    long long ans = 0;
    int mi = 1e9, d = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += abs(a[i]);
        if (a[i] < 0) {
            d++;
        }
        int z = abs(a[i]);
        mi = min(mi, z);
    }
    if (d & 1) {
        ans -= 2 * mi;
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
    cin >> test;
    while (test--) {
        solve();
    }
}