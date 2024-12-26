//problem "1819substr"
//created in 22:13:44 - Wed 27/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    int k;
    string s;
    cin >> k >> s;
    if (k == 0) {
        int d = 0;
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                d++;
            }
            else {
                ans += 1ll * d * (d + 1) / 2;
                d = 0;
            }
        }
        cout << ans + 1ll * d * (d + 1) / 2 << "\n";
        return;
    }
    int j = 0, last = -1, cnt = 0;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            cnt++;
        }
        while (cnt > k) {
            if (s[j] == '1') {
                last = j;
                cnt--;
            }
            j++;
        }
        if (cnt == k) {
            while (s[j] != '1') {
                j++;
            }
            ans += j  - last;
        }
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