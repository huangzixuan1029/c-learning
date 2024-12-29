#include<iostream>
#include<cstdbool>
using namespace std;
int max(int a,int b)
{
    return (a > b ? a : b);
}
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *getNewNode(int data)
{
    struct Node *tree = new (struct Node);
    tree->data=data;
    tree->left=NULL;
    tree->right = NULL;
    return tree;
}
struct Node *Insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if(data<root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
bool search(Node*root,int data)
{
    if(root==NULL)
    {
        return false;
    } 
    else if(root->data==data)
        return true;
    else if(root->data>data)
        return search(root->left, data);
    else return search(root->right, data);
}
int FindHeight(struct Node*root)
{
    if(root==NULL)
    return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}//这是一个用来看二叉树高度的函数，也是使用了递归，可以画图理解
int main()
{
    Node*root=NULL;
    root = Insert(root, 15);
    root = Insert(root, 14);
    root = Insert(root, 13);
    root = Insert(root, 23);
    root = Insert(root, 22);
    root = Insert(root, 21);
    root = Insert(root, 20);
    int num;
    cin>>num;
    if(search(root,num)==true)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    int height = FindHeight(root);
    cout << height << endl;

    return 0;
}
