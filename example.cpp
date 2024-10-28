#include <bits/stdc++.h>
#define f(i,x,n,y) for(int i=x;i<=n;i+=y)
#define f2(i,n,x,y) for(int i=n;i>=x;i-=y)
#define ll long long
#define task "test"

using namespace std;
ll n,k,pre[19],d[20],pos[19],a[19];

void out()
{
 f(x,1,n,1)
  cout<<pos[x]<<" ";
 exit(0);
}

void check()
{
 for (int i = 0; i <= n; i++) {
    d[i] = pre[i] = 0;
 }
 f(i,1,n,1)
  {
   pre[pos[i]]+=a[i];
   d[pos[i]]++;
  }
 pre[0]=pre[1];
 f(i,1,k,1)
   {
    if(d[i]==0||pre[i-1]!=pre[i])
        return;
   }
  out();
}

void Try (ll i)
{
 f(j,1,k,1)
  {
   pos[i]=j;
   if(i==n)
    check();
   else
    Try(i+1);
  }
}

void solve ()
{
  ll res=0;
  cin>>n>>k;
  f(i,1,n,1){
    cin>>a[i];
    res+=a[i];}
  if(res%k!=0)
   {
    cout<<"ze";
   }
  else
    Try(1);
}

int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
 freopen(task".inp","r",stdin);
 freopen(task".out","w",stdout);
 solve();
 return 0;
}