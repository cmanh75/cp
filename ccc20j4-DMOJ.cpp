//problem "ccc20j4-DMOJ"
//created in 10:36:38 - Mon 14/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string s, t;

void solve() {
    cin >> s >> t;
    for (int i = 0; i < t.size(); i++) {
        t = t + t[0];
        t.erase(0, 1);
        for (int j = 0; j < s.size() - t.size() + 1; j++) {
            if (t == s.substr(j, t.size())) {
                cout << "yes";
                return;
            }
        }
    }
    cout << "no";
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