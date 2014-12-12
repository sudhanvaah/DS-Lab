//Circular linked list concatenation
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* link;
};
typedef node * NODE;
NODE getnode(int t)
{
    NODE x=(NODE)malloc(sizeof(node));
    x->link=x;
    x->data=t;
    return x;
}
NODE insert_rear(NODE last,int t)
{
    NODE temp=getnode(t),r=last;
    if(last==NULL)
        return temp;
    temp->link=last->link;
    last->link=temp;
    return temp;
}
NODE concat(NODE last1,NODE last2)
{
    NODE temp;
    temp=last1->link;
    last1->link=last2->link;
    last2->link=temp;
    return last2;
}
void disp(NODE last)
{
    if(last==NULL)
     {
      cout<<"\nEmpty list";
      return;
     }
    NODE f=last->link;
    cout<<"\nList is ";
    while(f!=last)
        {
         cout<<f->data<<" ";
         f=f->link;
        }
    cout<<f->data<<" ";
}
main()
{
    NODE last1,last2,last;
    last1=last2=NULL;
    int n;
    cout<<"\nEnter elements of list 1 (-1 to terminate) ";
    cin>>n;
    while(n!=-1)
    {

        last1=insert_rear(last1,n);
        cin>>n;
    }
    cout<<"\nEnter elements of list 2 (-1 to terminate) ";
    cin>>n;
    while(n!=-1)
    {

        last2=insert_rear(last2,n);
        cin>>n;
    }
    last=concat(last1,last2);
    cout<<"\nConcated list is: ";
    disp(last);
    return 0;
}
