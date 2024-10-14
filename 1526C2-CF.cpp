//problem "1526C2-CF"
//created in 16:56:46 - Fri 11/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

void solve() {
    int n, ans = 0;
    priority_queue < int, vector < int >, greater < int > > pq;
    cin >> n;
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        s += x;
        ans++;
        while (s < 0) {
            s -= pq.top();
            pq.pop();
            ans--;
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