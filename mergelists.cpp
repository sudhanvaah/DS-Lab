#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
int data;
node* link;
};
typedef node * NODE;
NODE getnode()
{
NODE x=(NODE)malloc(sizeof(node));
return x;
}
NODE ins_ord(int t,NODE root)
{
    NODE temp=getnode(),curr=root;
    temp->data=t;
    temp->link=NULL;
    if(root==NULL)
        return temp;
    if(t<root->data)
    {
        temp->link=root;
        return temp;
    }
    while(curr->link!=NULL && t>curr->link->data)
        curr=curr->link;
    temp->link=curr->link;
    curr->link=temp;
    return root;
}
NODE merge_(NODE root1,NODE root2)
{
    NODE temp=root1,root=root1,r=root1;
    int t;
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;
    while(temp->link!=NULL)
        temp=temp->link;
    temp->link=root2;
    while(root->link!=NULL)
    {
            r=root;
            if(r->link->link==NULL)
            {
                if(r->data>r->link->data)
                 {
                     t=r->data;
                     r->data=r->link->data;
                     r->link->data=t;
                 }

            }
            while(r->link!=NULL)
            {
            if(root->data>r->data)
            {
                 t=r->data;
                 r->data=root->data;
                 root->data=t;
            }
            r=r->link;
            }
        root=root->link;
    }
    return root1;
}
void disp(NODE root)
{
if(root==NULL)
{
cout<<"\nEmpty list";
return;
}
cout<<"\nList is ";
while(root!=NULL)
{
cout<<root->data<<" ";
root=root->link;
}
}
main()
{
NODE root1=NULL,root2=NULL,root;
int i=1;
int n;
cout<<"\nEnter first list";
while(i)
{
cout<<"\n1 to enter element\n0 to finish entering ";
cin>>i;
if(i==1)
{
cout<<"\nEnter element ";
cin>>n;
root1=ins_ord(n,root1);
}
}
i=1;
cout<<"\nEnter second list";
while(i)
{
cout<<"\n1 to enter element\n0 to finish entering ";
cin>>i;
if(i==1)
{
cout<<"\nEnter element ";
cin>>n;
root2=ins_ord(n,root2);
}
}
disp(root1);
disp(root2);
root=merge_(root2,root1);

disp(root);
return 0;
}
