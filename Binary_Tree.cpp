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
class Node
{
public:
    T data;
    bool leftside;
    Node *left, *right, *parent;
    Node(T x)
    {
        data = x;
        left = NULL;
        right = NULL;
        parent = this;
        leftside = true;
    }
    ~Node()
    {

    }
};
template <typename T>
void insertnoderight(Node<T> *parent, Node<T> *node)
{
    node->right = parent->right;
    parent->right = node;
    node->parent = parent;
    node->leftside = false;
    return;
}

template <typename T>
void insertnodeleft(Node<T> *parent, Node<T> *node)
{
    node->left = parent->left;
    parent->left = node;
    node->leftside = true;
    node->parent = parent;
    return;
}

template <typename T>
void inorder(Node<T> *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
    return;
}

template <typename T>
Node<T> *depp(Node<T> *temp)
{
    if (temp == NULL)
        return NULL;
    if ((temp->left == NULL) && (temp->right == NULL))
    {
        // cout<<temp->data;
        return temp;
    }
    Node<T> *t1 = depp(temp->left);
    Node<T> *t2 = depp(temp->right);
    if (t1 != NULL)
        return t1;
    if (t2 != NULL)
        return t2;
    return NULL;
}

template <typename T>
void deletenode(Node<T> *temp)
{

    Node<T> *t = depp(temp);
    if (t->parent == t)
    {
        free(t);
        return;
    }
    temp->data = t->data;
    if ((t->leftside) == true)
        (t->parent)->left = NULL;
    else
        (t->parent)->right = NULL;
    free(t);
}

int main()
{
    Node<int> *n=new Node<int>(5);
    Node<int> *n1=new Node<int>(6);
    // n.parent=&n;
    insertnoderight(n, n1);
    // cout<<(n1.right==NULL);
    // cout<<depp(&n)->data;
    // delete n1;
    deletenode(n1);
    inorder(n);
    return 0;
}
