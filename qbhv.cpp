//problem "permutation"
//created in 20:41:32 - Wed 09/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, x[N], d[N];
map < string, bool > f;
string s;
vector < string > ans;

void cal(int i) {
    if (i > n) {
        string t = "";
        for (int j = 1; j <= n; j++) {
            t = t + s[x[j] - 1];
        }
        if (!f.count(t)) {
            f[t] = 1;
            ans.push_back(t);
        }
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!d[j]) {
            d[j] = 1;
            x[i] = j;
            cal(i + 1);
            d[j] = 0;
        }
    }
}

void solve() {
    cin >> s;
    n = s.size();
    cal(1);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (string z : ans) {
        cout << z << "\n";
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