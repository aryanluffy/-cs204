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
struct Point{
  lli x,y;
};
Point Fixed;
int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
    if (val == 0) return 0;   
    return (val > 0)? 1: 2;  
} 
bool compare(Point a,Point b){
     lli a_dist=(a.x-Fixed.x)*(a.x-Fixed.x)+(a.y-Fixed.y)*(a.y-Fixed.y);
     lli b_dist=(b.x-Fixed.x)*(b.x-Fixed.x)+(b.y-Fixed.y)*(b.y-Fixed.y);
     int ort=orientation(Fixed,a,b);
     if(ort==0)return a_dist<b_dist;
     if(ort==1)return 0; 
     else return 1;
}
int main() 
{ 
  fastio;
  int t;cin>>t;
  vt <Point> pnts;
  while(t--){
     lli x,y;cin>>x>>y;
     pnts.pb({x,y});
  }
  lli x=pnts[0].x;
  f(i,0,pnts.size()) x=min(x,pnts[i].x);
  vt<Point> temp;
  f(i,0,pnts.size()){
    if(x==pnts[i].x){temp.pb(pnts[i]);}
  }
  lli y=temp[0].y;
  f(i,0,temp.size()){
    y=min(y,temp[i].y);
  }
  f(i,0,temp.size()){
     if(y==temp[i].y){
       Fixed=temp[i];
       break;
     }
  }
  f(i,0,pnts.size())if(Fixed.x==pnts[i].x && Fixed.y==pnts[i].y){swap(pnts[0],pnts[i]);break;}
  sort(pnts.begin(),pnts.end(),compare);
  vt <Point> newarr;
  newarr.pb(Fixed);
  f(i,1,pnts.size()-1){
     if(orientation(Fixed,pnts[i],pnts[i+1])){
        newarr.pb(pnts[i]);
     }
  }
  newarr.pb(pnts.back());
  if(newarr.size()<3){
    //cout<<-1;
    return 0;
  }
  vt <Point> STACK;
  STACK.pb(newarr[0]);
  STACK.pb(newarr[1]);
  STACK.pb(newarr[2]);
  //cout<<newarr.size()<<"\n";
  f(i,3,newarr.size()){
        Point p2=STACK.back();
        Point p1=STACK[STACK.size()-2];
    while(orientation(p1,p2,newarr[i])==1){STACK.pop_back();
        p2=STACK.back();
        p1=STACK[STACK.size()-2];
    };
    STACK.pb(newarr[i]);
  }
  //cout<<"\n";
  //cout<<"FIXED "<<Fixed.x<<" "<<Fixed.y<<"\n";
  cout<<STACK.size()<<"\n";
  reverse(STACK.begin(),STACK.end());
  f(i,STACK.size()-1,2*STACK.size()-1){
    cout<<STACK[i%STACK.size()].x<<" "<<STACK[i%STACK.size()].y<<"\n"; 
  }
  return 0; 	
}
