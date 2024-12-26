//problem "327-marisa"
//created in 17:50:28 - Thu 21/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, c[N];
vector < int > a[N];

void dfs(int i, int pa) {
    c[i] = 1;
    for (int j : a[i]) {
        if (j != pa) {
            dfs(j, i);
            c[i] += c[j];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << c[i] << " ";
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