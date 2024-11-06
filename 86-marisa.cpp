//problem "86-marisa"
//created in 20:42:52 - Wed 06/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k, a[N];

bool check(int x) {
    int pre = 1, z = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] >= a[pre] + x) {
            z++;
            pre = i;
        }
    }
    return z >= k;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = 1e9, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
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