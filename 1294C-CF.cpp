//problem "1294C-CF"
//created in 20:16:03 - Mon 07/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            a = i;
            n /= a;
            break;
        }
    }
    if (a == 0) {
        cout << "NO" << "\n";
        return;
    }
    for (int i = a + 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            b = i;
            n /= b;
            break;
        }
    }
    if (b == 0 || (n == b)) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    cout << a << " " << b << " " << n << "\n";
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