//problem "findnum-vnoj"
//created in 11:44:12 - Wed 09/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27};
int n;
long long ans = 1e18;

void cal(int i, int s, long long t) {
    if (i == 10) {
        if (s == 1) {
            ans = min(ans, t);
        }
        return;
    }
    long long z = 1;
    for (int j = 0; t <= 1e18 / z ; j++, z *= a[i]) {
        if (s % (j + 1) == 0) {
            cal(i + 1, s / (j + 1), t * z);
        }
    }
}

void solve() {
    cin >> n;
    cal(0, n, 1);
    cout << ans;
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