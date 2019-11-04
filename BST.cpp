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
class BST
{
public:
struct node 
{ 
    int key; 
    struct node *LEFT, *RIGHT; 
}; 
struct node *ROOT=NULL;
struct node *newNode(int item) 
{ 
    struct node *temp =  new struct node; 
    temp->key = item; 
    temp->LEFT = temp->RIGHT = NULL; 
    return temp; 
} 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->LEFT); 
        cout<<root->key<<" ";
        inorder(root->RIGHT); 
    } 
} 

struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
        node->LEFT  = insert(node->LEFT, key); 
    else if (key > node->key) 
        node->RIGHT = insert(node->RIGHT, key);    
    return node; 
} 
struct node * successor(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->LEFT != NULL) 
        current = current->LEFT; 
    return current; 
} 
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->key) 
        root->LEFT = deleteNode(root->LEFT, key); 
    else if (key > root->key) 
        root->RIGHT = deleteNode(root->RIGHT, key); 
    else
    { 
        if (root->LEFT == NULL) 
        { 
            struct node *temp = root->RIGHT; 
            free(root); 
            return temp; 
        } 
        else if (root->RIGHT == NULL) 
        { 
            struct node *temp = root->LEFT; 
            free(root); 
            return temp; 
        } 
        struct node* temp = successor(root->RIGHT); 
        root->key = temp->key; 
        root->RIGHT = deleteNode(root->RIGHT, temp->key); 
    } 
    return root; 
} 
};

int main() 
{ 
    
    return 0; 
}
