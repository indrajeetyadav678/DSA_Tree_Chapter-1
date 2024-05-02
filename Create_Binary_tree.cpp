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
int main(){
    node *root=new node(10);
    root->L=new node(20);
    root->R=new node(30);
    root->L->R=new node(7);
    root->R->L=new node(40);
    cout<<"0-->"<<root->L->R->data<<"-->"<<root->L->data<<"-->"<<root->data<<"-->"<<root->R->data<<"-->"<<root->R->L->data<<"-->0";
    
    
}