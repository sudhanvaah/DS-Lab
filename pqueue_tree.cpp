//Priority Queue using binary search tree
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node *r,*l;
};
typedef node * NODE;
NODE getnode(int t)
{
    NODE temp=(NODE)malloc(sizeof (node));
    temp->data=t;
    temp->l=temp->r=NULL;
    return temp;
}
NODE ins(NODE tree,int t)
{
    NODE p,q;
    if(tree==NULL)
    {
        q=getnode(t);
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
    q=getnode(t);
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
NODE del(NODE root)
{
    if(root==NULL)
    {
        cout<<"\nUnderflow";
        return NULL;
    }
    NODE temp=root;
    if(temp->l==NULL)
    {
        free(temp);
        return root->r;
    }
    while(temp->l->l!=NULL)
        temp=temp->l;
    if(temp->l->r==NULL)
        temp->l=NULL;
    else
        temp->l=temp->l->r;
    return root;
}
main()
    {
    NODE tree=NULL;
    int n=1,t;
    while(n)
    {
    cout<<"\n1 to insert\n2 to delete\n3 for display\n0 to exit ";
    cin>>n;
    switch(n)
    {
        case 1: cout<<"\nEnter element ";
                cin>>t;
               tree=ins(tree,t);break;
        case 2: tree=del(tree);break;
        case 3: intrav(tree);break;
    }
    }
    return 0;
    }
