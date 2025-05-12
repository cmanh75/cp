//problem "example1"
//created in 22:16:16 - Tue 11/02/2025
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

const int N = 2e5 + 5;
typedef pair<int, int> pii;

int n, m, trie[N * 20][2], cnt = 0, a[N];

void add(int x) {
    int i = 0;
    for (int j = 30; j >= 0; j--) {
        int z = ((x >> j) & 1);
        if (!trie[i][z]) {
            trie[i][z] = ++cnt;
        }
        i = trie[i][z];
    }
}

int get(int x) {
    int i = 0, ans = 0;
    for (int j = 30; j >= 0; j--) {
        int z = ((x >> j) & 1);
        if (trie[i][1 ^ z]) {
            i = trie[i][1 ^ z];
            ans += (1 << j);
        }
        else {
            i = trie[i][z];
        }
    }
    return ans;
}

void solve() {  
    cin >> n;
    add(0);
    int s = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s ^= a[i];
        add(s);
        ans = max(ans, get(s));
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