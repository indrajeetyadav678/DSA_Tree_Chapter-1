#include <iostream>
using namespace std;
class node
{
public:
    int data;
    class node *L;
    class node *R;

    node(int d)
    {
        data = d;
        L = NULL;
        R = NULL;
    }
};
void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->L);
    preorder(root->R);
}
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->L);
    cout << root->data << " ";
    inorder(root->R);
}
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->L);
    postorder(root->R);
    cout<<root->data<<" ";
}
int main(){
    node *root=new node(10);
    root->L=new node(20);
    root->R=new node(30);
    cout<<"\n preorder =>";
    preorder(root);
    cout<<"\n inorder =>";
    inorder(root);
    cout<<"\n postorder =>";
    postorder(root);
}