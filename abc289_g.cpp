//problem "abc289_g"
//created in 14:01:16 - Tue 03/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N];

struct line {
    int x;
    long long y;
    long long value(int a) {
        return 1ll * a * x + y;
    }
    bool bad_line(line a,line b) {
        return (double)(a.y - y)/(x - a.x) <= (double)(a.y - b.y) / (b.x - a.x);
    }
};
struct convex_hull_trick {
    vector <line> s;
    void add_line(line c) {
        while (s.size() > 1 && c.bad_line(s[s.size() - 2], s.back())) {
            s.pop_back();
        }
        s.push_back(c);
    }
    long long binary_searchh(int a) {
        int l = 0, r = s.size() - 2;
        line ans = s.back();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (s[mid].value(a) <= s[mid + 1].value(a)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = s[mid];
            }
        }
        return ans.value(a);
    }
};

void solve() {
    convex_hull_trick w;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) {
        w.add_line({n - i + 1, 1ll * (n - i + 1) * a[i]});
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cout << w.binary_searchh(x) << " ";
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