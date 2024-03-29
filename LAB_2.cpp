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
struct point
{
  ld x,y;
  point *link=NULL; 
};
int Length(point *root)
{
  int len=0;
  while(root!=NULL){len++;root=root->link;}
  return len;
}
void AddFirst(int x,int y,point **root)
{
   point *temp=(point *)malloc(sizeof(point));
   temp->x=x,temp->y=y;
   if(*root!=NULL)
   {
      temp->link=*root;
      *root=temp;
   }
   else *root=temp;
}

int DelFirst(point **root)
{
   if(*root==NULL) return -1;
   point *temp=*root;
   *root=(*root)->link;
   free(temp);
   return 0;
}
int Del(int x,int y,point **root)
{
	point *temp2=*root;
	if(temp2==NULL){
		return -1;
	}
    if(temp2->x==x && temp2->y==y)
    {
      DelFirst(root);
      return 0;
    }
    while(temp2->link!=NULL)
    {
      if(temp2->link->x==x && temp2->link->y==y)
      {
          point *temp=temp2->link;
          temp2->link=(temp2->link)->link;
          free(temp);
          return 0;
      }
      else
      temp2=temp2->link;
    }
    return -1;
}
bool Search(int x,int y,point *root)
{
   while(root!=NULL)
   {
     if(root->x==x && root->y==y)
      return 1;
     root=root->link;
   }
   return 0;
}
void Search(ld d,point *root)
{
   int cnt=0;
   while(root!=NULL)
   {
    if((root->x)*(root->x)+ (root->y)*(root->y)<=d*d) cnt++;
    root=root->link;
   }
   cout<<cnt<<"\n";
}
void Show(point *root)
{
	while(root!=NULL){cout<<root->x<<root->y<<" ";root=root->link;}
	cout<<"\n";
}
string arr[]={"False","True"};
int main() 
{ 
  fastio;
  int t;cin>>t;
  point *X=NULL;
  point **root=&X;
  while(t!=0)
  {
    t--;
    int x;cin>>x;
    if(x==1)
    {
      int y,z;cin>>y>>z;
      AddFirst(y,z,root);
    }
    else if(x==2)
    {
      int temp=DelFirst(root);
      if(temp)cout<<temp<<"\n";
    }
    else if(x==3)
    {
      int y,z;cin>>y>>z;
      int temp=Del(y,z,root);
      if(temp)cout<<temp<<"\n";
    }
    else if(x==4)
    {
      ld y;cin>>y;
      Search(y,*root);
    }
    else if(x==5)
    {
      ld y,z;cin>>y>>z;
      cout<<arr[Search(y,z,*root)]<<"\n";
    }
    else
    {
      cout<<Length(*root)<<"\n";
    }
  }
  //Show(*root);
  return 0;     
}
