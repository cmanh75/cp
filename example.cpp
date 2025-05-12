#include <bits/stdc++.h>
#define ll int
#define fi first
#define se second
#define pb push_back
#define task "test"

const ll N=1e5+9;
const ll mxN= 1e6+9;
const ll Nmax=1e9+9;

using namespace std;
ll n,tt,k,q,a[N];
struct pt {ll l,r,x,pos;};
pt t[N];
ll d[N],b[N],ansc[N];
bool cmp (pt a,pt b)
{
 if(a.l/k==b.l/k)
  return a.r<b.r;
 return a.l/k<b.l/k;    
}

void update(int x, int v) {
    b[d[x]]--;
    d[x] += v;
    b[d[x]]++;
}

void solve ()
{
 cin>>n>>q;
 for(ll i=1;i<=n;i++){
   cin>>a[i];}
 k=sqrt(n);  
 for(ll i=1;i<=q;i++){
   cin>>t[i].l>>t[i].r>>t[i].x;
   t[i].pos=i;
 }
 sort(t + 1, t + 1 + q, cmp);
 ll i=1,j=0,ans=0;
 for(ll z=1;z<=q;z++)
  {
    while (i < t[z].l) {
        update(a[i++], -1);
    }
    while (i > t[z].l) {
        update(a[--i], 1);
    }
    while (j < t[z].r) {
        update(a[++j], 1);
    }
    while (j > t[z].r) {
        update(a[j--], -1);
    }
    ansc[t[z].pos]=b[t[z].x];    
  }
 for(ll i=1;i<=q;i++)
  cout<<ansc[i]<<'\n'; 
}


int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
 if(fopen(task".INP", "r")) {
  freopen(task".INP", "r", stdin);
  freopen(task".OUT", "w", stdout);
 }
 tt=1;
 while(tt--)
  solve();
 return 0;
}


/*


1 2 3 4

r=4

while(j>r)
{
i--;
d[a[i]]++;
}


5 2
2 2 3 1 4
1 5 1
1 3 2

*/