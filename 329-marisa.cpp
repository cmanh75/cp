//problem "329-marisa"
//created in 17:35:17 - Thu 31/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
vector < long long > s;
long long a[N], t = 0, k;

void cal2(int i) {
    if (i > n) {
        int u = lower_bound(s.begin(), s.end(), k - t) - s.begin();
        if (u < s.size() && s[u] == k - t) {
            cout << "YES";
            exit(0);
        }
        return;
    }
    cal2(i + 1);
    if (t + a[i] <= k) {
        t += a[i];
        cal2(i + 1);
        t -= a[i];
    }
}

void cal1(int i) {
    if (i > n / 2) {
        s.push_back(t);
        return;
    }
    cal1(i + 1);
    if (t + a[i] <= k) {
        t += a[i];
        cal1(i + 1);
        t -= a[i];
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cal1(1);
    sort(s.begin(), s.end());
    cal2(n / 2 + 1);
    cout << "NO";
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