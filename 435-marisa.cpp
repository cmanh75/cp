//problem "435-marisa"
//created in 15:16:14 - Thu 07/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
map < int, int > d;

void solve() {
    int x, y;
    cin >> x >> y;
    int u = __gcd(x, y);
    x /= u;
    y /= u;
    string s;
    int pre = 0;
    cin >> s;
    d[0] = 1;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            pre += y;
        }
        else {
            pre -= x;
        }
        ans += d[pre];
        d[pre]++;
    }
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