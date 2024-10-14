//problem "1068-CSES"
//created in 19:58:38 - Wed 09/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;

void dequy(int n) {
    cout << n << " ";
    if (n == 1) {
        return;
    }
    if (n % 2 != 0) {
        dequy(n * 3 + 1);
    }
    else {
        dequy(n / 2);
    }
}

void solve() {
    cin >> n;
    dequy(n);
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