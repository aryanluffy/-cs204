//The MAP2, MAP3 and MAP4 are mere arrays. The approach works in O(nlogn) time. 
//First store all the variables in MAP2 and all the querries in queries.
//Then sort MAP2.
//MAP3 is the array obtained by deleting duplicates in MAP2.
//MAP4 is the array which contains the current values for a query for the variable at the ith position in the MAP3.
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
lli evaluate(node *root,vt <string> &MAP3,vt <string> &MAP4)
{
   string s=root->s;
   lli ans=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^" && s!="#")
   {
     int pos=lb(MAP3.begin(),MAP3.end(),s)-MAP3.begin();
     if(pos==MAP3.size())return stoi(s);
     if(MAP3[pos]!=s)return stoi(s);
     return stoi(MAP4[pos]);
   }
   else
   {
     lli lans=evaluate(root->lch,MAP3,MAP4),rans=0;
     if(root->rch!=NULL)rans=evaluate(root->rch,MAP3,MAP4);
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
       ans=-evaluate(root->lch,MAP3,MAP4);
     }
     
   }
   return ans;
}
node* construct_tree(vt <string> &postfix,vt <string> &MAP3,vt <string> &MAP4)
{
   node *root=NULL;
   vt <node*> stk;
   int i=0;
   while(i!=postfix.size())
   {
     if(postfix[i]!="+" && postfix[i]!="-" && postfix[i]!="*" && postfix[i]!="/" && postfix[i]!="^" && postfix[i]!="#")
       {
         node *temp=(node *)malloc(sizeof(node));
         if(isalpha(postfix[i][0]))
         {
           int pos=lb(MAP3.begin(),MAP3.end(),postfix[i])-MAP3.begin();
           if(pos==MAP3.size())return NULL;
           if(MAP3[pos]!=postfix[i])
              return NULL;
           else
           {
             if(MAP4[pos]=="")
               return NULL;
             else
             {
               temp->s=postfix[i];
               stk.pb(temp);
             } 
           }
         }
         else
         {
           temp->s=postfix[i];
           stk.pb(temp);
         }
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
    vt <string> MAP2;
    vt <pair<vt <string>,string>> queries(n);
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
          if(i==j||s[i-1]=='('|| s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='^'||s[i-1]=='*'||s[i-1]=='/')
          {
            s1.push_back('#');
            continue;
          }
        }
        s1.push_back(s[i]);
      }
      //cout<<s1<<"\n";
      vt <string> postfix=stringTovector(s1);
      postfix=infixToPostfix(postfix);
      queries[k].first=postfix;
      queries[k].second=temp;
      if(j)
      {
        MAP2.pb(temp);
      }
    }
    sort(MAP2.begin(),MAP2.end());
    vt <string> MAP3;
    for(int i=0;i<(int)MAP2.size()-1;i++)
    {
      if(MAP2[i]!=MAP2[i+1])
        MAP3.pb(MAP2[i]);
    }
    if(MAP2.size()>0)
    MAP3.pb(MAP2.back());
    vt <string> MAP4(MAP3.size(),"");
    f(k,0,n)
    {
      if(queries[k].second=="")
      {
        node *root=construct_tree(queries[k].first,MAP3,MAP4);
        if(root==NULL)
            cout<<"CAN'T BE EVALUATED\n";
        else
            cout<<evaluate(root,MAP3,MAP4)<<"\n";  
      }
      else
      {
        int pos=lb(MAP3.begin(),MAP3.end(),queries[k].second)-MAP3.begin();
        node *root=construct_tree(queries[k].first,MAP3,MAP4);
        if(root!=NULL)MAP4[pos]=to_string(evaluate(root,MAP3,MAP4));
      }
    }
  }
  return 0; 	
}
