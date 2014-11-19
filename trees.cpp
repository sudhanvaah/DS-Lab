//Binary search tree
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node *r,*l;
};
typedef node * NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof (node));
    return x;
}
NODE make(int t)
{
    NODE temp=getnode();
    temp->data=t;
    temp->l=temp->r=NULL;
    return temp;
}
NODE ins(NODE tree,int t)
{
    NODE p,q;
    if(tree==NULL)
        {
            q=make(t);
            return q;
        }
    p=q=tree;
    while(q!=NULL)
        {
            p=q;
            if(t<q->data)
                q=q->l;
            else
                q=q->r;
        }
    q=make(t);
    if(t<p->data)
        p->l=q;
    else
        p->r=q;
    return tree;
}
void intrav(NODE tree)
{
    if(tree==NULL)
        return;
    intrav(tree->l);
    cout<<tree->data<<" ";
    intrav(tree->r);
}
void pretrav(NODE tree)
{
    if(tree==NULL)
        return;
    cout<<tree->data<<" ";
    pretrav(tree->l);
    pretrav(tree->r);
}
void posttrav(NODE tree)
{
    if(tree==NULL)
        return;
    posttrav(tree->l);
    posttrav(tree->r);
    cout<<tree->data<<" ";
}
main()
{
    NODE tree=NULL;
    int n=1,t;
    while(n)
    {
    cout<<"\n1 to insert\n2 for preorder display\n3 for postorder display \n4 for inorder display\n0 to exit ";
    cin>>n;
    switch(n)
     {
        case 1: cout<<"\nEnter element ";
                cin>>t;
                tree=ins(tree,t);
                break;
        case 2: pretrav(tree);break;
        case 3: posttrav(tree);break;
        case 4: intrav(tree);break;
        case 0: break;
     }

    }
    return 0;
}
