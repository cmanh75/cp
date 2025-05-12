//problem "subseq"
//created in 20:38:22 - Wed 15/01/2025
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, x, a[N];

void solve() {
    cin >> n >> x;
    vector < int > s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.push_back(a[i] - x);
        s.push_back(a[i] + x);
        s.push_back(a[i]);
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