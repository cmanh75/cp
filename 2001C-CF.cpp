#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N], d[N], l[N][N];

void query(int x, int y) {
    cout << "? " << x << " " << y << endl; 
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            l[i][j] = 0;
        }
    }
    vector < pair < int, int > > e;
    for (int i = 1; i < n; i++) {
        int x;
        int y = n ;
        while (i != y) {
            query(i, y);
            cin >> x;
            if (x == i || x == y) {
                if (!l[i][y]) {
                    e.push_back(make_pair(i, y));
                }
                l[i][y] = l[y][i] = 1;
                break;
            }
            y = x;
        }
    }
    cout << "! ";
    for (pair < int, int > j : e) {
        cout << j.first << " " << j.second << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test;
    cin >> test;
    while (test--) {
        solve();
    }
}