//problem "2039B-CF"
//created in 21:44:11 - Sat 23/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;\
map < char, int > d;

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cout << s[i - 1] << s[i] << "\n";
            return;
        }
    }
    for (int i = 2; i < s.size(); i++) {
        if (s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i] != s[i - 2]) {
            cout << s[i - 2] << s[i - 1] << s[i] << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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