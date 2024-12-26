//problem "80-marisa"
//created in 13:28:39 - Sun 10/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], ll, rr;

void solve() {
    cin >> n >> ll >> rr;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int j = 2; j <= n; j++) {
        int l = 1, r = j - 1, u = j, v = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] >= ll - a[j]) {
                u = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        l = 1, r = j - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] <= rr - a[j]) {
                v = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        ans += v - u + 1;
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