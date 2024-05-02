#include <iostream>
using namespace std;

class node // self reference class
{
public:
    int data;
    class node *L; // self reference class
    class node *R; // self reference class

    node(int d)
    {
        data = d;
        L = NULL;
        R = NULL;
    }
};

node *bst(node *root, int v){
    if(root==NULL){
        return new node(v);
    }
    if(v<root->data){
        root->L=bst(root->L,v);
    }
    else{
        root->R= bst(root->R,v);
    }
    return root;
}
void inorder(node *root){
if(root==NULL){
    return;
}
inorder(root->L);
cout<<root->data<<"  ";
inorder(root->R);
}
int main()
{
    node *root = new node(10);
    root->L = new node(20);
    root->R = new node(30);
    root=bst(root,15);
    inorder(root);
    // node(50);
}
