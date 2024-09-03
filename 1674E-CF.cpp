//problem "1674E-CF"
//created in 13:38:17 - Wed 28/08/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1e9;
    for (int i = 2; i <= n; i++) {
        int x = a[i];
        int y = a[i - 1];
        if (x < y) {
            swap(x, y);
        }
        int l = 0, r = y / 2;
        while (l <= r) {
            int mid = (l + r) / 2;
        }
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
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}