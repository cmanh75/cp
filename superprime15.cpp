//problem "superprime15"
//created in 22:33:55 - Wed 27/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool check(long long x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    long long z = 0, n;
    cin >> n;
    while (n != 0) {
        z = z * 10 + n % 10;
        n /= 10;
    }
    n = 0;
    while (z != 0) {
        n = n * 10 + z % 10;
        if (!check(n)) {
            cout << "KHONG";
            return;
        }
        z /= 10;
    }   
    cout << "PHAI";
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