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
const lli tp=1e7+19;
bool hash_table[5][tp];
lli primes[5];
lli prime_powers[114][101];
lli calc_hash(string s,lli p){
    lli hash=0;
    f(i,0,s.size()){
        if(s[i]<='Z')
            hash=((hash+(s[i]-'A'+26)*(prime_powers[p][i])))%tp;
        else hash=((hash+(s[i]-'a')*(prime_powers[p][i])))%tp;
    }
    if(hash<0)hash+=tp;
    return hash;
}
int main() 
{ 
  fastio;
  int n;cin>>n;
  vt <string> s(n);
  f(i,0,n)cin>>s[i];
  primes[0]=3;
  primes[1]=11;
  primes[2]=31;
  primes[3]=101;
  primes[4]=113;
  prime_powers[3][0]=prime_powers[11][0]=prime_powers[31][0]=prime_powers[101][0]=prime_powers[113][0]=1;
  f(i,1,101){
      f(j,0,5){
          prime_powers[primes[j]][i]=(primes[j]*prime_powers[primes[j]][i-1])%tp;
      }
  }  
  f(i,0,n){
      f(j,0,5){
          hash_table[j][calc_hash(s[i],primes[j])]=1;
      }
  }
  f(i,0,n){
      string temp=s[i];
      reverse(s[i].begin(),s[i].end());
      if(temp==s[i])continue;
      int cnt=0;
      f(j,0,5){
          cnt+=hash_table[j][calc_hash(s[i],primes[j])];
      }
      if(cnt==5){
          cout<<"YES\n";
          return 0;
      }
  }
  cout<<"NO\n";
  return 0; 	
}
