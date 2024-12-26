//problem "cses1090"
//created in 12:59:13 - Fri 15/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, x, a[N];

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, res = 0;
    for (int i = n; i >= l; i--) {
        res++;
        if (a[i] + a[l] <= x) {
            l++;
        }
    }
    cout << res;
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