//Circular linked list
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
NODE insert_rear(NODE last,int t)
{
    NODE temp=getnode(),r=last;
    temp->data=t;
    temp->link=temp;
    if(last==NULL)
        return temp;
    temp->link=last->link;
    last->link=temp;
    return temp;
}
NODE insert_front(NODE last,int t)
{
    NODE temp=getnode();
    temp->data=t;
    temp->link=temp;
    if(last==NULL)
        return temp;
    temp->link=last->link;
    last->link=temp;
    return last;
}
NODE insert_pos(NODE last,int n,int p)
{
    NODE curr=last->link,temp=getnode(),t=last;
    int c=1;
    temp->data=n;
    temp->link=temp;
    if(last==NULL)
        return temp;
    while(curr!=last)
    {
        if(c==p)
            break;
        curr=curr->link;
        t=t->link;
        c++;
    }
    temp->link=curr;
    t->link=temp;
    if(c<p)
        return temp;
    return last;
}
NODE delete_front(NODE last)
{
    if(last==NULL)
        {
        cout<<"\nUnderflow";
        return last;
        }
    if(last->link==last)
        {
            cout<<"\n"<<last->data<<" is deleted";
            free(last);
            return NULL;
        }
    NODE first=last->link;
    last->link=first->link;
    cout<<"\n"<<first->data<<" is deleted";
    free(first);
    return last;
}
NODE delete_rear(NODE last)
{
    NODE curr=last;
    if(last==NULL)
        {
        cout<<"\nUnderflow";
        return last;
        }
    if(last->link==last)
        {
            cout<<"\n"<<last->data<<" is deleted";
            free(last);
            return NULL;
        }
    while(curr->link!=last)
        curr=curr->link;
    curr->link=last->link;
    cout<<"\n"<<last->data<<" is deleted";
    free(last);
    return curr;
}
NODE delete_pos(NODE last,int p)
{
    NODE first=last->link,temp=last;
    int c=1;
    if(last==NULL)
        {
            cout<<"\nUnderflow";
            return last;
        }
    if(last->link==last)
        {
            cout<<"\n"<<last->data<<" is deleted";
            free(last);
            return NULL;
        }
    if(p==1)
        return delete_front(last);
    while(first!=last)
    {
        if(c==p)
            break;
        temp=temp->link;
        first=first->link;
        c++;
    }
    temp->link=first->link;
    cout<<"\n"<<first->data<<" is deleted";
    free(first);
    if(c<p)
        return temp;
    return last;

}
void disp(NODE last)
{

    if(last==NULL)
     {
      cout<<"\nEmpty list";
      return;
     }
     NODE l=last->link;
    cout<<"\nList is ";
    while(l!=last)
        {
         cout<<l->data<<" ";
         l=l->link;
        }
    cout<<l->data<<" ";

}
main()
{
 NODE last=NULL;
 int i=1;
 int n;
 while(i)
 {
    cout<<"\n\n1 to insert at rear\n2 to insert at front \n3 to insert at position\n4 to delete from front";
    cout<<"\n5 to delete from rear\n6 to delete from position\n7 to display\n0 to exit\n";
    cin>>i;
    if(i==1)
        {
         cout<<"\nEnter element ";
         cin>>n;
         last=insert_rear(last,n);
        }
    else if(i==2)
        {
         cout<<"\nEnter element ";
         cin>>n;
         last=insert_front(last,n);
        }
    else if(i==3)
        {
         int p;
         cout<<"\nEnter element ";
         cin>>n;
         cout<<"\nEnter position ";
         cin>>p;
         last=insert_pos(last,n,p);
        }
    else if(i==4)
        last=delete_front(last);
    else if(i==5)
        last=delete_rear(last);
    else if(i==6)
        {
         int p;
         cout<<"\nEnter position ";
         cin>>p;
         last=delete_pos(last,p);
        }
    else if(i==7)
        disp(last);
 }
return 0;
}
