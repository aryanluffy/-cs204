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
map <string,string> MAP;
vector<string> stringTovector(string s)
{
    int n = s.length();
    vector<string> stv;
    for(int i = 0; i<n;i++)
    {
        string temp="";
        if((s[i] >= '0' && s[i] <= '9') || isalpha(s[i])) 
        {
            int j = i;
            while(i!=s.size() && s[i] >= '0' && s[i] <= '9' || isalpha(s[i]))
            {
                temp+=s[i];
                i++;
            }
            i--;
        }
        else 
        {
            temp+=s[i];
        }
        stv.pb(temp);
    }
    return stv;
}
int prec(string c) 
{ 
    if(c=="#")
      return 4;
    else if(c == "^") 
    return 3; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "+" || c == "-") 
    return 1; 
    else
    return -1; 
} 
vector<string> infixToPostfix(vector<string> s) 
{ 
    stack<string> st; 
    st.push("N"); 
    int l = s.size(); 
    vector<string> ns;
    for(int i = 0; i < l; i++) 
    { 
        if((s[i][0] >= '0' && s[i][0] <= '9')) 
            ns.pb(s[i]);
        else if(isalpha(s[i][0]))ns.pb(s[i]);    
        else if(s[i] == "(") 
           st.push("("); 
        else if(s[i] == ")") 
        { 
            while(st.top() != "N" && st.top() != "(") 
            { 
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c);
            } 
            if(st.top() == "(") 
            { 
                string c = st.top(); 
                st.pop(); 
            } 
        } 
        else{ 
            while(st.top() != "N" && prec(s[i]) <= prec(st.top())) 
            { 
                if(s[i]=="^"&&st.top()=="^") break;
                string c = st.top(); 
                st.pop(); 
                ns.push_back(c); 
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(st.top() != "N") 
    { 
        string c = st.top(); 
        st.pop(); 
        ns.push_back(c); 
    }     
    return ns;
} 

struct node
{
  string s;
  node* lch=NULL,*rch=NULL;
};
lli evaluate(node *root)
{
   string s=root->s;
   lli ans=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^" && s!="#")
   {
     if(MAP.find(s)==MAP.end())return stoi(s);
     return stoi(MAP[s]);
   }
   else
   {
     lli lans=evaluate(root->lch),rans=0;
     if(root->rch!=NULL)rans=evaluate(root->rch);
     if(s=="+")
       ans=lans+rans;
     else if(s=="-")
       ans=lans-rans;
     else if(s=="*")
       ans=lans*rans;
     else if(s=="/")
       ans=lans/rans;
     else if(s=="^")
     {
       ans=1;
       if(rans<0)ans=0;
       f(i,0,rans)ans*=lans;
     }
     else
     {
       ans=-evaluate(root->lch);
     }
     
   }
   return ans;
}
node* construct_tree(vt <string> postfix)
{
   node *root=NULL;
   vt <node*> stk;
   int i=0;
   while(i!=postfix.size())
   {
     if(postfix[i]!="+" && postfix[i]!="-" && postfix[i]!="*" && postfix[i]!="/" && postfix[i]!="^" && postfix[i]!="#")
       {
         node *temp=(node *)malloc(sizeof(node));
         temp->s=postfix[i];
         stk.pb(temp);
       } 
     else if(postfix[i]!="#")
     {
       if(stk.size()<2)return NULL;
       node *s1=stk.back();
       stk.pop_back();
       node *s2=stk.back();
       stk.pop_back();
       node *temp=(node *)malloc(sizeof(node));
       temp->s=postfix[i];
       temp->lch=s2;
       temp->rch=s1;
       stk.pb(temp); 
     }
     else
     {
       if(stk.size()<1)return NULL;
       node *s1=stk.back();
       stk.pop_back();
       node *temp=(node *)malloc(sizeof(node));
       temp->lch=s1;
       temp->s="#";
       stk.pb(temp);
     }
     i++;
   }
   if(stk.size()!=1)return NULL;
   return stk.back();
}
void traverse(node *root)
{
  if(root==NULL)return ;
  cout<<root->s<<"\n";
  traverse(root->lch);
  traverse(root->rch);
}
int main() 
{ 
  //fastio;
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    f(k,0,n)
    {
      string s,s1;
      cin>>s;
      bool flag=false;
      f(j,0,s.size())if(s[j]=='=')flag=true;
      int j=0;
      string temp="";
      if(flag)
      {
        while(s[j]!='='){temp.pb(s[j]),j++;}
        j++;
      }
     f(i,j,s.size())
      {
        if(s[i]=='-')
        {
          if(i==0||s[i-1]=='('|| s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='^'||s[i-1]=='*'||s[i-1]=='/')
          {
            s1.push_back('#');
            continue;
          }
        }
        s1.push_back(s[i]);
      }
      vt <string> postfix=stringTovector(s1);
      postfix=infixToPostfix(postfix);
      node* root=construct_tree(postfix);
      int f2=0;
      f(y,0,postfix.size())if(isalpha(postfix[y][0])){
        if(MAP.find(postfix[y])==MAP.end())
          f2=1;
      }
      if(flag){
        if(MAP.find(temp)==MAP.end())
        MAP.ist({temp,"70"});
        if(!f2)
        MAP[temp]=to_string(evaluate(root));
        else
        {
          MAP.erase(temp); 
        }
        continue;
      } 
      if(f2){
        cout<<"CANT BE EVALUATED\n";
        continue;
      }
      if(root!=NULL)
      cout<<evaluate(root)<<"\n";
      else cout<<"CANT BE EVALUATED\n";
    }
    MAP.clear();
  }
  return 0; 	
}
