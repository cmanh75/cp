//problem "cses1755"
//created in 22:28:00 - Mon 18/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int d[N];

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        d[s[i] - 'A']++;
    }
    int odd = 0, cs;
    for (int i = 0; i < 26; i++) {
        if (d[i] % 2 == 1) {
            odd++;
            cs = i;
        }
    }
    if (odd > 1) {
        cout << "NO SOLUTION";
        return;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= d[i] / 2; j++) {
            cout << (char)(i + 'A');
        }
    }
    if (s.size() % 2 != 0) {
        cout << (char)(cs + 'A');
    }
    for (int i = 26; i >= 0; i--) {
        for (int j = 1; j <= d[i] / 2; j++) {
            cout << (char)(i + 'A');
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