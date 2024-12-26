#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int k;
pair < int, int > f[N][22];
string s;

pair < int, int > get(int l, int r) {
    int o = log2(r - l + 1);
    return max(f[l][o], f[r - (1 << o) + 1][o]);
}

void solve() {
    cin >> s >> k;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        f[i][0] = make_pair(s[i], -i);
    }
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 0; j <= n - (1 << i); j++) {
            f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }
    int i = 0;
    while (k != 0 && i + k < n) {
        pair < int, int > u = get(i, i + k);
        cout << s[-u.second];
        k -= -u.second - i;
        i = -u.second + 1;
    }
    if (k == 0) {
        for (int j = i; j < n; j++) {
            cout << s[j];
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
    int test = 1;
    while (test--) {
        solve();
    }
}   
