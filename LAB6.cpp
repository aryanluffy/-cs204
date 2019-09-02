#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds; 
lli tmod(lli x,lli m){return (x%m+m)%m;}//USE AT YOUR OWN RISK
v64 userid,distuserid,val;
v4096 queries; 
int main() 
{ 
  fastio;
  lli n,q;cin>>n>>q;
  queries.resize(q);
  f(i,0,q)
  {
     int t;
     cin>>t;
     if(t==1)
     {
       lli u,a;cin>>u>>a;
       queries[i].pb(1),queries[i].pb(u),queries[i].pb(a);
       userid.pb(u);
     }
     else queries[i].pb(2);
  }
  sort(userid.begin(),userid.end());
  for(int i=0;i<(int)userid.size()-1;i++)
    {
      if(userid[i]!=userid[i+1])
        distuserid.pb(userid[i]);
    }
    if(userid.size()>0)
    distuserid.pb(userid.back());
    val.resize(distuserid.size());
    f(i,0,val.size())val[i]=0;
  int maxid=0;  
  f(i,0,queries.size())
  {
    if(queries[i][0]==1)
    {
      int pos=lb(distuserid.begin(),distuserid.end(),queries[i][1])-distuserid.begin();
      val[pos]+=queries[i][2];
      if(maxid==0)
          maxid=queries[i][1];
      else {
        int pos2=lb(distuserid.begin(),distuserid.end(),maxid)-distuserid.begin();
        if(val[pos2]<val[pos])
          maxid=queries[i][1];
      }  
    }
    else
    {
      if(maxid==0)cout<<"No data available.\n";
      else cout<<maxid<<"\n";
    }
  }
  return 0; 	
}
