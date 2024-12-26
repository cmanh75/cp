//problem "89-marisa"
//created in 22:14:18 - Mon 25/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long x, num, res;

bool check(long long k) {
    long long p = 1, ans = 0;
    for (int i = 1; i <= 18; i++) {
        if (p * 10 > k) {
            ans += (k - p + 1) * i;
            break;
        }
        else {
            ans += p * 9 * i;
            p = p * 10;
        }
    }
    num = ans;
    return ans < x;
}

void solve() {
    cin >> x;
    long long l = 1, r = 1e17, ans;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            res = num;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    x -= res;
    ans++;
    vector < int > z;
    while (ans != 0) {
        z.push_back(ans % 10);
        ans /= 10;
    }
    reverse(z.begin(), z.end());
    cout << z[x - 1];
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