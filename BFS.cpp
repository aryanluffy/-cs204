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
template <typename T> 
void DEBUG_ARR(vt<T> a)
{
	f(i,0,a.size())cout<<a[i]<<" ";
	cout<<"\n";
}
int popcount(lli x){
    int ans=0;
    while(x>0){
        if((x&1)==1)ans++;
        x=x>>1;
    }
    return ans;
}
v32 graph[100001];
bool is_it_visited[100001];

int main() 
{ 
  fastio;
  int n,m;cin>>n>>m;
  f(i,0,m){
      int u,v;cin>>u>>v;
      graph[u].pb(v);
      graph[v].pb(u);
  }
  f(i,1,n+1){
      if(is_it_visited[i]==0){
          queue <int> Q;
          Q.push(i);
          is_it_visited[i]=1;
          while(Q.size()!=0){
              int s=Q.front();
              cout<<s<<" ";
              Q.pop();
              for(auto x:graph[s]){
                  if(is_it_visited[x]==0){
                       is_it_visited[x]=1;
                       Q.push(x); 
                  }
              }
          }       
      }
      cout<<"\n";
  }  
  return 0; 	
}
