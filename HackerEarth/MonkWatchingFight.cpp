#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int value)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insertnode(struct node *root, int value)
{
    if(root==NULL) return createnode(value);
    
    if(root->data >= value) root->left = insertnode(root->left, value);
    
    else root->right = insertnode(root->right, value);
    
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int height(struct node *root)
{
    if(root==NULL) return 0;
    
    else
    {
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(lh > rh) return lh+1;
        
        return rh+1;
    }
}
int main()
{
    int n, x, i;
    struct node *root = NULL;
    
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        if(root==NULL) root=insertnode(root, x);
        else insertnode(root, x);
    }
    //inorder(root);
    cout<<height(root)<<endl;
    return 0;
}
