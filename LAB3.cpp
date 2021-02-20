#include <bits/stdc++.h>
using namespace std;
// 10 ^ 8
#define fi(nn) for(int i = 0;i<nn;i++)
#define fir(nn) for(int i = nn-1;i>=0;i--)
#define fi1(nn,aa) for(int i = 0; i< nn; i+=aa)
#define fir1(nn,en) for(int i = nn-1;i>=en;i--)
#define fi2(init,nn,aa) for(int i = init; i< nn; i+=aa)
#define fir2(nn,en,aa) for(int i = nn-1;i>=en;i-=aa)
#define fj(nn) for(int j = 0;j<nn;j++)
#define fj1(nn,aa) for(int j = 0; j< nn; j+=aa)
#define fj2(init,nn,aa) for(int j = init; j< nn; j+=aa)
#define lli long long int  
#define line cout<<endl;
#define vc vector<char>
#define vi vector<int>
#define vlli vector<lli>
// function to check if paranthesis are balanced 

bool ParanthesisBalanced(string a) 
{ 
	stack<char> s;
	s.push('0'); 
	vi count(5,0);
	vi check(5,0);
	fi(a.length())
	{
		switch(a[i])
		{
			case '(':
				s.push('(');
				count[0]++;
			break;
			case '{':
				s.push('{');
				count[1]++;
			break;
			case '[':
				s.push('[');
				count[2]++;
			break;
			case '<':
				s.push('<');
				count[3]++;
			break;
			case '|':          //edit this please but later
				if(s.top()=='|')
					{s.pop();
					count[4]--;}
				else
					{s.push('|');
					count[4]++;}									
			break;
			case ')':
				if(s.top()=='(')
					{s.pop();
					count[0]--;}
				else
					{return false;}
			break;
			case '}':
				if(s.top()=='{')
					{s.pop();
					count[1]--;}
				else
					{return false;}
			break;
			case ']':
				if(s.top()=='[')
					{s.pop();
					count[2]--;}
				else
					{return false;}
			break;
			case '>':
				if(s.top()=='<')
					{s.pop();
					count[3]--;}
				else
					{return false;}
			break;						
		}
	}
	if(count!=check||s.top()!='0')
		return false;
 	return true;
}
  
int main () 
{ /*
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  */
	lli q ;
	cin>> q;
	string s;
	while(q--)
	{
		cin>>s;
		bool check1 = true ;
		fi(s.length())
		{
			if(s[i]=='('||s[i]=='{'||s[i]=='['||s[i]=='<'||s[i]=='>'||s[i]==']'||s[i]=='}'||s[i]==')'||s[i]=='|')
				{continue;}
			else{
				check1 = false;
				break;
			}
		}
		if(!check1)
		{
			cout<<"NO";
			continue;
		}
		if(ParanthesisBalanced(s))
		{
			cout<<"YES";line
		}
		else{
			cout<<"NO";line
		}
	}

	
	
    return 0; 
}
