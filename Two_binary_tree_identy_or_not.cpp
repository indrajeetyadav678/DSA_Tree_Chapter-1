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
    bool isidenty2(node *h1, node *h2)
    {
        if (h1 == NULL && h2 == NULL)
        {
            return true;
        }
        if (h1 != NULL && h2 == NULL)
        {
            return false;
        }
        if (h1 == NULL && h2 != NULL)
        {
            return false;
        }
        bool left = isidenty2(h1->L, h2->L);
        bool right = isidenty2(h1->R, h2->R);
        bool curval = h1->data == h2->data;
        if (left && right && curval)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// bool isidenty(node *h1, node *h2)
// {
//     if (h1 == NULL && h2 == NULL)
//     {
//         return true;
//     }
//     if (h1 != NULL && h2 == NULL)
//     {
//         return false;
//     }
//     if (h1 == NULL && h2 != NULL)
//     {
//         return false;
//     }
//     bool left = isidenty(h1->L, h2->L);
//     bool right = isidenty(h1->R, h2->R);
//     bool curval = h1->data == h2->data;
//     if (left && right && curval)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

int main()
{
    node *root1 = new node(10);
    root1->L = new node(20);
    root1->R = new node(30);
    node *root2 = new node(10);
    root2->L = new node(20);
    root2->R = new node(30);
    // root2->L->R=new node(50);
    // bool c = isidenty(root1, root2);
    // if (c)
    // {
    //     cout << "trees are identy trees\n";
    // }
    // else
    // {
    //     cout << "trees are not identy trees'n";
    // }

    bool c1 =root1->isidenty2(root1, root2);
    
    if (c1)
    {
        cout << "trees are identy tree\n";
    }
    else
    {
        cout << "trees are not identy trees\n";
    }
}