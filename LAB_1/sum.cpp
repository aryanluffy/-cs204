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
bool string_compare(string a,string b)
{
  if(a.size()!=b.size())return a.size()>b.size();
  f(i,0,a.size())
  {
    if(a[i]==b[i])continue;
    else if(a[i]>b[i])return 1;
    else return 0;
  }
  return 1;
}
string sum(string a,string b)
{
  string s;
  int carry=0;
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  f(i,0,min(a.size(),b.size()))
  {
    int x=a[i]-'0',y=b[i]-'0';
    if(x+y+carry>=10)
    {
      s+='0'+x+y+carry-10;
      carry=1;
    }
    else
    {
      s+='0'+x+y+carry;
      carry=0;
    }
  }
  f(i,min(a.size(),b.size()),max(a.size(),b.size()))
  {
    if(a.size()>b.size())
    {
      int x=a[i]-'0';
    if(x+carry>=10)
    {
      s+='0'+x+carry-10;
      carry=1;
    }
    else
    {
      s+='0'+x+carry;
      carry=0;
    }
    }
    else
    {
       int x=b[i]-'0';
    if(x+carry>=10)
    {
      s+='0'+x+carry-10;
      carry=1;
    }
    else
    {
      s+='0'+x+carry;
      carry=0;
    }
    }
  }
  if(carry)s+='1';
  reverse(s.begin(),s.end());
  return s;
} 
string diff(string a,string b)
{
    string s;
  int carry=0;
  bool x=string_compare(a,b);
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  if(!x)
  {
    string c=a;
    a=b;
    b=c;
  }
  f(i,0,b.size())
  {
    int x=a[i]-b[i];
    if(x>=0)
      s+='0'+a[i]-b[i];
    else
    {
      s+='0'+10+a[i]-b[i];
      a[i+1]--;
    }
  }
  int pos=b.size();
  f(i,b.size(),a.size())
  {
    if(a[i]>='0'){pos=i;break;}
    else
    {
      s+='9';
      a[i]='9';
      a[i+1]--;
    }
  }
  f(i,pos,a.size())s+=a[i];
  while(s[s.size()-1]=='0')s.pop_back();
  if(!x)s+='-';
  reverse(s.begin(),s.end());
  if(s.size()==0)s+='0';
  return s;
}
string multiply(string a,string b){
  string s="0";
  fd(i,b.size()-1,-1)
  {
    string x="0";
    f(j,0,b[i]-'0')
    x=sum(x,a);
    f(j,0,b.size()-i-1)x+="0";
    s=sum(s,x);
  }
  return s;
}
string divide(string a,string b)
{
  string quotient;
  if(string_compare(a,b)==0)return "0";
  int pos=0;
  string remainder;
  while(pos!=a.size())
  { 
    int multiplier=0;
    remainder+=a[pos];
    string temp;
    while(string_compare(remainder,temp) && multiplier<=10){multiplier++;temp=sum(temp,b);}
    temp=diff(temp,b);
    if(string_compare(remainder,temp)==1)remainder=diff(remainder,temp);
    if(remainder[0]=='0')remainder.pop_back();
    quotient+=multiplier+'0'-1;
    pos++;
  }
  reverse(quotient.begin(),quotient.end());
  while(quotient[quotient.size()-1]=='0')quotient.pop_back();
  reverse(quotient.begin(),quotient.end());
 return quotient;
}
string remainder(string a,string b)
{
  string s=divide(a,b);
  s=diff(a,multiply(s,b));
  return s;
}
bool is_prime(lli x)
{
  for(int i=2;i*i<=x;i++)
  {
    if(x%i==0)return 0;
  }
  if(x==1)return 0;
  return 1;
}
int main() 
{ 
  fastio;
  int t;cin>>t;
  while(t!=0)
  {
  	t--;
  	string a,b;cin>>a>>b;
    cout<<sum(a,b)<<"\n";
  }

  return 0;     
}
