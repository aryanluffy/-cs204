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
class RMQ  //gives index of min-max in a given range
{
    public:
	struct node
    {
	int mn,mx,l,r; 
    };
	v32 h;
	vt <node> st;
 
    bool is_intersection(int l,int r,int ll,int rr)
    {
       if(r<ll || rr<l)
         return 0;
         return 1;
    }
	RMQ(v32 a)
	{
       h=a;
       st.resize(4*h.size());
       build(0,h.size()-1);
	}
	void build(int l,int r,int k=0)
	{
		st[k].l=l,st[k].r=r;
	    if(l==r)
		   {st[k].mx=st[k].mn=l;
             return;
		   }
	    build(l,(l+r)/2,2*k+1);
	    build((l+r)/2+1,r,2*k+2);
	    if(h[st[2*k+1].mn]<=h[st[2*k+2].mn])
	    st[k].mn=st[2*k+1].mn;
	    else st[k].mn=st[2*k+2].mn;	
        if(h[st[2*k+1].mx]>=h[st[2*k+2].mx])
	    st[k].mx=st[2*k+1].mx;
	    else st[k].mx=st[2*k+2].mx;
	}
    int minquery(int l,int r,int k=0)
    {
        if(l>r)return MAXN;
        int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
        if(ll>=l && rr<=r)
         return st[k].mn;
   	    int ans=l;   
   	    if(!(r<ll || mid<l))
   	       ans=minquery(l,r,2*k+1);
   	    if(!(r<mid+1 || rr<l))
   	     {if(h[ans]>h[minquery(l,r,2*k+2)])	
   	       ans=minquery(l,r,2*k+2);}
   	    return ans;     
    }
	int maxquery(int l,int r,int k=0)
    {
       if(l>r)return -MAXN;
       int ll=st[k].l,rr=st[k].r,mid=(ll+rr)/2;
       if(ll>=l && rr<=r)
          return st[k].mx;
   	   int ans=l;   
   	   if(!(r<ll || mid<l))
   	      ans=maxquery(l,r,2*k+1);
   	   if(!(r<mid+1 || rr<l))
   	      {
		   int y=maxquery(l,r,2*k+2);
		   if(h[ans]<h[y])	
   	           ans=y;
	      }
   	   return ans;     
    }
    void update(int id,int val,int k=0)
    {
        int l=st[k].l,r=st[k].r,mid=(l+r)/2;
        if(l==r)
        {
            h[l]=val;
            return;
        }
        if(id>=l && id<=mid)
        update(id,val,2*k+1);
        if(mid+1<= id && id<=r)
        update(id,val,2*k+2);
        if(h[st[2*k+1].mn]<=h[st[2*k+2].mn])
	    st[k].mn=st[2*k+1].mn;
	    else st[k].mn=st[2*k+2].mn;	
        if(h[st[2*k+1].mx]>=h[st[2*k+2].mx])
	    st[k].mx=st[2*k+1].mx;
	    else st[k].mx=st[2*k+2].mx;
    }
};
int popcount(lli x){
    int ans=0;
    while(x>0){
        if((x&1)==1)ans++;
        x=x>>1;
    }
    return ans;
}
v32 graph[100001],wt[100001];
vt <pair<int,int>> MST;
void getmst(int n){
  v32 arr_segtree(n+1,MAXN);
  v32 nodes(n+1,0);
  RMQ ST(arr_segtree);
  set <int> mstSet;
  ST.update(1,0);
  while(mstSet.size()!=n){
     int u=ST.minquery(1,n);
     mstSet.insert(u);
     ST.update(u,MAXN+1);
     if(u!=1){
         cout<<u<<" "<<nodes[u]<<"\n";
     }
     f(i,0,graph[u].size()){
         int x=graph[u][i];
         int w=wt[u][i];
         if(ST.h[x]!=MAXN+1 && ST.h[x]>w){
             ST.update(x,w);
             nodes[x]=u;
         }
     }
  }
}
int main() 
{ 
  fastio;
  int n,m;
  cin>>n>>m;
  f(i,0,m){
      int u,v,w;
      cin>>u>>v>>w;
      graph[u].pb(v);
      graph[v].pb(u);
      wt[u].pb(w);
      wt[v].pb(w);
  }
  getmst(n);
  return 0; 	
}
