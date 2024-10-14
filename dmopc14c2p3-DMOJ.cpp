//problem "dmopc14c2p3-DMOJ"
//created in 00:11:46 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater < int > ());
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1ll * a[i] * b[i];
    }
    cout << sum;
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