//problem "319C-CF"
//created in 08:58:11 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], b[N];
long long dp[N];

struct line {
    int x;
    long long y;
    long long get(int a) {
        return 1ll * a * x + y;
    }
    bool bad_line(line a, line b) {
        return 1.0 * (y - a.y) / (a.x - x) <= 1.0 * (b.y - a.y) / (a.x - b.x);
    }
};

struct cht {
    vector < line > s;
    void add(line a) {
        while (s.size() > 1 && a.bad_line(s[s.size() - 2], s.back())) {
            s.pop_back();
        }
        s.push_back(a);
    }
    long long bs(int a) {
        int l = 0, r = s.size() - 2;
        long long ans = s.back().get(a);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (s[mid].get(a) >= s[mid + 1].get(a)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = s[mid].get(a);
            }
        }
        return ans;
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    cht w;
    w.add({b[1], 0});
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = w.bs(a[i]);
        w.add({b[i], dp[i]});
    }
    cout << dp[n];
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