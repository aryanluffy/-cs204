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
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
char arr[256];
int main() 
{ 
  fastio;
  f(i,0,256)arr[i]=-1;
  arr['(']=0;arr['{']=1;arr['[']=2;arr['<']=3;arr['|']=4;arr[')']=5;arr['}']=6;arr[']']=7;arr['>']=8;
  int n;cin>>n;
  while(n--)
  {
    string s;cin>>s;
    vt <char> stk;
    int flag=true;
    f(i,0,s.size())
    {
       if(arr[s[i]]==-1){
         flag=false;
         break;
       }
       if(arr[s[i]]<4)
         stk.pb(s[i]);
       else if(arr[s[i]]>4)
         {
           if(stk.size()==0)
             {
               flag=false;
               break;
             }
            else {
              if(arr[stk[stk.size()-1]]==arr[s[i]]-5)
                  stk.pop_back();
              else {
                 flag=false;
                 break;
              }    
            } 
         }
        else
        {
           if(stk.size()!=0 && stk[stk.size()-1]=='|')
             stk.pop_back();
           else stk.pb('|');    
        } 
    }
    if(flag==true && stk.size()==0)cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0; 	
}
