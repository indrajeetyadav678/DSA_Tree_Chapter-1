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
    int height(node *h)
    {
        if (h == NULL)
        {
            return 0;
        }
        int left = height(h->L);
        int right = height(h->R);
        int result = max(left, right) + 1;
        return result;
    }
    bool isbalance(node *h)
    {
        if (h == NULL)
        {
            return true;
        }
        bool left = isbalance(h->L);
        bool right = isbalance(h->R);
        bool diff = abs(height(h->L) - height(h->R)) <= 1;
        if (left && right && diff)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{    //   0<-2<-10->30->40
    node *root = new node(10);
    root->L = new node(2);
    root->R = new node(30);
    root->R->R = new node(40);
    root->R->R->R = new node(50);
    // root->L->L->R=new node(60);
    bool c=root->isbalance(root);
    if(c){
        cout<<"\nTree is the balance tree";
    }
    else{
        cout<<"\nTree is not the balance tree";
    }
}
