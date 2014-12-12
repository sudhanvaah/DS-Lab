//Check palindrome using doubly linked list
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    char data;
    node * r,* l;
};
typedef node * NODE;
NODE getnode(char a)
{
    NODE x=(NODE)malloc(sizeof(node));
    x->data=a;
    x->l=x->r=NULL;
    return x;
}
NODE insert_front(char a[])
{
    NODE temp,temp2,head;
    temp=getnode(a[0]);
    head=temp;
    for(int i=1;a[i]!='\0';i++)
        {
            temp2=getnode(a[i]);
            temp->r=temp2;
            temp2->l=temp;
            temp=temp2;
        }
    return head;
}
int chkpal(NODE head)
{
    NODE h=head;
    while(h->r!=NULL)
        h=h->r;
    while(head->r!=NULL)
    {
        if(head->data!=h->data)
            return 0;
        h=h->l;
        head=head->r;
    }
    return 1;
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
   /* while(head->next!=NULL)
        head=head->next;
    while(head!=NULL)
        {
         cout<<head->data<<" ";
         head=head->prev;
        }*/
}
main()
{
 NODE head=NULL;
 int i=1;
 int n;
 char a[20];
 cout<<"\nEnter string ";
 cin>>a;
 head=insert_front(a);
 if(chkpal(head))
    cout<<"\nPalindrome";
 else
    cout<<"\nNot palindrome";
return 0;
}
