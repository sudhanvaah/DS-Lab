//Binary tree
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct node
{
    int data;
    node *l,*r;
};
typedef node* NODE;
NODE getnode(int t)
{
    NODE x=(NODE)malloc(sizeof(node));
    x->data=t;
    x->l=x->r=NULL;
    return x;
}
NODE ins(NODE tree,int t,char s[])
{
    NODE temp=getnode(t),curr=tree;
    int i;
    if(tree==NULL)
        return temp;
    for( i=0;i<strlen(s)-1;i++)
    {
        if(s[i]=='l' or s[i]=='L')
            {
                curr=curr->l;
                if(curr==NULL)
                    break;
            }
        else if(s[i]=='r' or s[i]=='R')
            {
                curr=curr->r;
                if(curr==NULL)
                    break;
            }
        else
            {
                cout<<"\nIncorrect path";
                return tree;
            }
    }
    if(i<strlen(s)-1)
        {
            cout<<"\nIncorrect path";
            return tree;
        }
    else
    {
        if(s[i]=='r' or s[i]=='R')
        {
            if(curr->r!=NULL)
            {
                cout<<"\nElement already exists at the given path";
                return tree;
            }
            curr->r=temp;
        }
        else if(s[i]=='l' or s[i]=='L')
        {
            if(curr->l!=NULL)
            {
                cout<<"\nElement already exists at the given path";
                return tree;
            }
            curr->l=temp;
        }
    }
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
main()
{
    int n=1,t;
    NODE root=NULL;
    char a[20];
    while(n)
    {
        cout<<"\n1 to insert\n2 to display\n0 to exit ";
        cin>>n;
        if(n==1)
            {
                cout<<"\nEnter element ";
                cin>>t;
                cout<<"\nEnter path ";
                cin>>a;
            root=ins(root,t,a);
            }
        if(n==2)
            intrav(root);
    }

}
