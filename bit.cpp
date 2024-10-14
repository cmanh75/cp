//problem "bit"
//created in 20:17:39 - Wed 09/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, x[N];

void cal(int i) {
    if (i > n) {
        for (int j = 1; j <= n; j++) {
            cout << x[j];
        }
        cout << "\n";
        return;
    }
    x[i] = 0;
    cal(i + 1);
    x[i] = 1;
    cal(i + 1);
}

void solve() {
    cin >> n;
    cal(1);
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