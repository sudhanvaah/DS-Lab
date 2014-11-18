//Doubly linked list
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node* next,* prev;
};
typedef node * NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(node));
    return x;
}
NODE insert_rear(NODE head,int t)
{
    NODE temp=getnode(),h=head;
    temp->data=t;
    temp->next=temp->prev=NULL;
    if(head==NULL)
        return temp;
    while(head->next!=NULL)
        head=head->next;
    head->next=temp;
    temp->prev=head;
    return h;
}
NODE insert_front(NODE head,int t)
{
    NODE temp=getnode();
    temp->data=t;
    temp->prev=NULL;
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}
NODE insert_pos(NODE head,int n,int p)
{
    NODE temp=getnode(),curr=head;
    int c=1;
    temp->data=n;
    temp->next=temp->prev=NULL;
    if(head==NULL)
        return temp;
    if(p==1)
        return insert_front(head,n);
    for(c=1;c<p-1 && curr->next!=NULL;c++,curr=curr->next);
    if(c<p-1)
        {
            temp->next=curr->next;
            curr->next=temp;
            temp->prev=curr;
            return head;
        }
    temp->next=curr->next;
    curr->next=temp;
    temp->prev=curr;
    (temp->next)->prev=temp;
    return head;
}
NODE delete_front(NODE head)
{
    NODE temp=head;
    if(head==NULL)
        {
        cout<<"\nUnderflow";
        return head;
        }
    cout<<"\n"<<head->data<<" is deleted";
    if(head->next==NULL)
        {
            free(head);
            return NULL;
        }
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}
NODE delete_rear(NODE head)
{
    NODE curr=head,temp;
    if(head==NULL)
        {
        cout<<"\nUnderflow";
        return head;
        }
    if(head->next==NULL)
        {
            cout<<"\n"<<head->data<<" is deleted";
            free(head);
            return NULL;
        }
    while(curr->next->next!=NULL)
        curr=curr->next;
    temp=curr->next;
    cout<<"\n"<<temp->data<<" is deleted";
    free(temp);
    curr->next=NULL;
    return head;
}
//here
NODE delete_pos(NODE head,int p)
{
    NODE temp=head,t;
    int c=1;
    if(head==NULL)
        {
            cout<<"\nUnderflow";
            return head;
        }
    if(head->next==NULL)
        {
            cout<<"\n"<<head->data<<" is deleted";
            free(head);
            return NULL;
        }
    if(p==1)
        return delete_front(head);
    while(temp!=NULL)
    {
        if(c==p)
            break;
        c++;
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
        return delete_rear(head);
    t=temp->prev;
    t->next=temp->next;
    (t->next)->prev=t;
    cout<<"\n"<<temp->data<<" is deleted";
    free(temp);
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
         head=head->next;
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
 while(i)
 {
    cout<<"\n\n1 to insert at rear\n2 to insert at front \n3 to insert at position";
    cout<<"\n4 to delete from front\n5 to delete from rear\n6 to delete from position";
    cout<<"\n7 to display\n0 to exit\n";
    cin>>i;
    if(i==1)
        {
         cout<<"\nEnter element ";
         cin>>n;
         head=insert_rear(head,n);
        }
    else if(i==2)
        {
         cout<<"\nEnter element ";
         cin>>n;
         head=insert_front(head,n);
        }
    else if(i==3)
        {
         int p;
         cout<<"\nEnter element ";
         cin>>n;
         cout<<"\nEnter position ";
         cin>>p;
         head=insert_pos(head,n,p);
        }
    else if(i==4)
        head=delete_front(head);
    else if(i==5)
        head=delete_rear(head);
    else if(i==6)
        {
         int p;
         cout<<"\nEnter position ";
         cin>>p;
         head=delete_pos(head,p);
        }
    else if(i==7)
        disp(head);
 }
return 0;
}
