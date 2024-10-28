//problem "584-marisa"
//created in 13:37:54 - Wed 23/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    stack < long long > st;
    stack < char > symbol;
    s = s + ".";
    long long num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }
        else {
            if (symbol.size() && (symbol.top() == '*' || s[i] == '/')) {
                long long x = st.top();
                st.pop();
                if (symbol.top() == '*') {
                    st.push(x * num);
                }
                else {
                    st.push(x / num);
                }
                symbol.pop();
            }
            else {
                st.push(num);
            }
            if (s[i] != '.') {
                symbol.push(s[i]);
            }
            num = 0;
        }
    }
    long long ans = 0;
    while (symbol.size()) {
        char ope = symbol.top();
        if (ope == '+') {
            ans += st.top();
        }
        else {
            ans -= st.top();
        }
        st.pop();
        symbol.pop();
    }
    cout << ans + st.top();
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