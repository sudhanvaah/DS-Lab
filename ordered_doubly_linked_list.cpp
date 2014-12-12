//Ordered doubly linked list
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node * l,* r;
};
typedef node * NODE;
NODE getnode(int t)
{
    NODE x=(NODE)malloc(sizeof(node));
    x->data=t;
    x->l=x->r=NULL;
    return x;
}
NODE ins(NODE head,int t)
{
    NODE temp=getnode(t),h=head;
    if(head==NULL)
        return temp;
    if(t<head->data)
    {
        temp->r=head;
        head->l=temp;
        return temp;
    }
    if(head->r==NULL)
    {
        head->r=temp;
        temp->l=head;
        return head;
    }
    while(t>h->r->data && h->r->r!=NULL)
        h=h->r;
    temp->r=h->r;
    h->r=temp;
    temp->l=h;
    if(temp->r!=NULL)
    {
        (temp->r)->l=temp;
    }

    return head;
}
void disp(NODE head)
{

    if(head==NULL)
     {
      cout<<"\nEmpty list";
      return;
     }
    cout<<"\nList is ";
    while(head!=NULL)
        {
         cout<<head->data<<" ";
         head=head->r;
        }
//    while(head->r!=NULL)
//        head=head->r;
//    while(head!=NULL)
//        {
//         cout<<head->data<<" ";
//         head=head->l;
//        }
}
main()
{
 NODE head=NULL;
 int i=1;
 int n;
 while(i)
 {
    cout<<"\n\n1 to insert\n2 to display\n0 to exit\n";
    cin>>i;
    if(i==1)
        {
         cout<<"\nEnter element ";
         cin>>n;
         head=ins(head,n);
        }
    else if(i==2)
        {
            disp(head);
        }
 }
return 0;
}
