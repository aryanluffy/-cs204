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
 
 bool compare(string s1,string s2)
 { 
   string s3=s1+s2,s4=s2+s1;
   return s3>s4;
 }

int main() 
{ 
  fastio;
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vt <string> s(n);
    f(i,0,n)cin>>s[i];
    sort(s.begin(),s.end(),compare);
    f(i,0,n)cout<<s[i];
    cout<<"\n";
  }
  return 0; 	
}
