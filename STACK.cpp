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
class STACK
{
    private:
    int arr[100000];
    int len=0;
public:
    int size(){
        return len;
    }
    int top(){
        if(len!=0)return arr[len-1];
        return -1;
    }
    void push(int x){
        len++;
        arr[len-1]=x;
    }
    void pop(){
        if(len==0)return;
        len--;
    }
};


int main() 
{ 
  fastio;
  STACK s;
  s.push(12);
  cout<<s.size()<<"\n";
  cout<<s.top()<<"\n";
  s.push(13);
  s.push(14);
  s.push(15);
  cout<<s.size()<<"\n";
  s.pop();
  s.pop();
  cout<<s.top()<<"\n";
  return 0; 	
}
