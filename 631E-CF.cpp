//problem "631E-CF"
//created in 09:25:15 - Sat 28/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], n;
long long s[N];

struct line {
    int x;
    long long y;
    long long get(int a) {
        return 1ll * a * x + y;
    }
    bool bad_line(line a, line b, int ok) {
        if (ok) {
            return 1.0 * (y - a.y) / (a.x - x) >= 1.0 * (b.y - a.y) / (a.x - b.x);
        }
        return 1.0 * (y - a.y) / (a.x - x) <= 1.0 * (b.y - a.y) / (a.x - b.x);
    }
};

struct cht {
    vector < line > s;
    void add(line a, int ok) {
        while (s.size() > 1 && a.bad_line(s[s.size() - 2], s.back(), ok)) {
            s.pop_back();
        }
        s.push_back(a);
    }
    long long bs(int a) {
        int l = 0, r = s.size() - 2;
        long long ans = s.back().get(a);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (s[mid].get(a) <= s[mid + 1].get(a)) {
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
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum = sum + 1ll * a[i] * i;
        s[i] = s[i - 1] + a[i];
    }
    cht w;
    long long ans = -1e18;
    for (int i = n; i > 0; i--)  {
        w.add({i, -s[i]}, 1);
        ans = max(ans, w.bs(a[i]) + s[i] - 1ll * a[i] * i);
    }
    w.s.clear();
    for (int i = 1; i <= n; i++)  {
        w.add({i, -s[i - 1]}, 0);
        ans = max(ans, w.bs(a[i]) + s[i - 1] - 1ll * a[i] * i);
    }
    cout << ans + sum;
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