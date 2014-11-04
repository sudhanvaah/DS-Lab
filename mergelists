//Merge two ordered linked lists
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
NODE insert_rear(int t,NODE root)
{
    NODE temp=getnode(),r=root;
    temp->data=t;
    temp->link=NULL;
    if(root==NULL)
        return temp;
    while(r->link!=NULL)
        r=r->link;
    r->link=temp;
    return root;
}
NODE merge_(NODE root1,NODE root2)
{
    NODE root,temp,temp2;
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;
    if(root1->data<=root2->data)
        root=root1;
    else
    {
        root=root2;
        root2=root1;
        root1=root;
    }
    temp=root;
    root1=root1->link;
    while(root2!=NULL && root1!=NULL)
    {
        if(root2->data<root1->data)
        {
            temp2=root2;
            root2=root2->link;
            temp2->link=temp->link;
            temp->link=temp2;
            temp=temp->link;
        }
        temp=root1;
        root1=root1->link;
    }
    if(root2!=NULL)
    {
        temp->link=root2;
    }
    return root;

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
			root1=insert_rear(n,root1);
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
			root2=insert_rear(n,root2);
		  }
 }
 root=merge_(root2,root1);
 disp(root);
return 0;
}
