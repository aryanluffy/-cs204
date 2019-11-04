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
class Node  
{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
};  
class AVL_TREE
{

  public:
    Node *root = NULL;
    int height(Node *N)  
    {  
    if (N == NULL)  
        return 0;  
    return N->height;  
    }  

Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    return node;  
}   
Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;   
    x->right = y;  
    y->left = T2;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;   
    return x;  
}  
 
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;   
    y->left = x;  
    x->right = T2;  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;   
    return y;  
}   
int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) -  
           height(N->right);  
}  
  
Node* insert(Node* node, int key)  
{  
    if (node == NULL)  
        return(newNode(key));  
    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else 
        return node;  
    node->height = 1 + max(height(node->left),  
                           height(node->right));  
    int balance = getBalance(node);  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);   
    if (balance > 1 && key > node->left->key)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
    if (balance < -1 && key < node->right->key)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
    return node;  
}  
Node * successor(Node* node)  
{  
    Node* current = node;  
    while (current->left != NULL)  
        current = current->left;  
    return current;  
}   
Node* deleteNode(Node* root, int key)  
{  
    if (root == NULL)  
        return root;  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
    else
    {  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;   
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else   
            *root = *temp; 
            free(temp);  
        }  
        else
        {   
            Node* temp = successor(root->right);  
            root->key = temp->key;  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }   
    if (root == NULL)  
    return root;   
    root->height = 1 + max(height(root->left),  
                           height(root->right));   
    int balance = getBalance(root);  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}   
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

};

int main()  
{  
    AVL_TREE root;
    root.root=root.insert(root.root, 9);  
     root.root=root.insert(root.root, 5);  
     root.root=root.insert(root.root, 10);  
     root.root=root.insert(root.root, 0);  
     root.root=root.insert(root.root, 6);  
     root.root=root.insert(root.root, 11);  
     root.root=root.insert(root.root, -1);  
     root.root=root.insert(root.root, 1);  
     root.root=root.insert(root.root, 2);  
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    root.preOrder(root.root);  
     root.root=root.deleteNode(root.root, 10);  
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";  
    root.preOrder(root.root);  
  
    return 0;  
}
