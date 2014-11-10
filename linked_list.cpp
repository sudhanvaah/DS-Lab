//Linked list
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
NODE insert_front(int t,NODE root)
{
    NODE temp=getnode();
    temp->data=t;
    temp->link=root;
    return temp;
}
NODE insert_pos(int t,NODE root,int p)
{
    NODE temp=getnode(),curr=root;
    int c=0;
    if(root==NULL)
     {
      root=insert_front(t,root);
      return root;
     }
    for(c=1;c<=p-2 && curr->link!=NULL;c++,curr=curr->link);
    temp->data=t;
    temp->link=curr->link;
    curr->link=temp;
    return root;
}
NODE delete_front(NODE root)
{
    if(root==NULL)
        {
        cout<<"\nUnderflow";
        return root;
        }
    NODE r=root;
    root=root->link;
    cout<<"\n"<<r->data<<" is deleted";
    free(r);
    return root;
}
NODE delete_rear(NODE root)
{
    NODE curr=root;
    if(root==NULL)
        {
        cout<<"\nUnderflow";
        return root;
        }
    if(root->link==NULL)
        return delete_front(root);
    for(curr=root;curr->link->link!=NULL;curr=curr->link);
    cout<<"\n"<<curr->link->data<<" is deleted";
    free(curr->link);
    curr->link=NULL;
    return root;
}
NODE delete_pos(NODE root,int p)
{
    NODE curr=root,temp;
    int c;
    if(p==1)
        return delete_front(root);
    for(c=1;c<p-1 && curr->link->link!=NULL;c++,curr=curr->link);
    temp=curr->link;
	 cout<<"\n"<<curr->link->data<<" is deleted";
	 curr->link=(curr->link)->link;
	 free(temp);
	 return root;

}
/*NODE delete_val(NODE root,int v)
{
    NODE next=root;
    int t=0;
    if(root==NULL)
    {
        cout<<"\nUnderflow";
        return NULL;
    }
    while(root->data==v)
    {
       root=root->link;
       t++;
       if(root==NULL)
        {
            cout<<"\n"<<t<<" occurance(s) of "<<v<<" deleted";
            return NULL;
        }
    }
    next=root;
    while(next->link!=NULL)
    {
        if(next->link->data==v)
            {
                t++;
                next->link=next->link->link;
            }
        if(next->link==NULL)
            break;
        next=next->link;
    }
    cout<<"\n"<<t<<" occurance(s) of "<<v<<" deleted";
    return root;
}
NODE reverse_list(NODE root)
{
    NODE curr=NULL,temp=root;
    if(root==NULL || root->link==NULL)
        return root;
    while(root!=NULL)
    {
        root=root->link;
        temp->link=curr;
        curr=temp;
        temp=root;
    }
    cout<<"\nList is reversed\n";
    return curr;
}*/
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
 NODE root=NULL;
 int i=1;
 int n;
 cout<<"\n\n1 to insert at rear\n2 to insert at front \n3 to insert at position\n4 to delete from front";
 cout<<"\n5 to delete from rear\n6 to delete from position\n7 to delete particular value";
 cout<<"\n8 to display\n0 to exit";
 while(i)
 {
	 cout<<"\nEnter choice ";
	 cin>>i;
	 if(i==1)
		  {
			cout<<"\nEnter element ";
			cin>>n;
			root=insert_rear(n,root);
		  }
	 else if(i==2)
		  {
			cout<<"\nEnter element ";
			cin>>n;
			root=insert_front(n,root);
		  }
	 else if(i==3)
		  {
			int p;
			cout<<"\nEnter element ";
			cin>>n;
			cout<<"\nEnter position ";
			cin>>p;
			root=insert_pos(n,root,p);
		  }
	 else if(i==4)
		  root=delete_front(root);
	 else if(i==5)
		  root=delete_rear(root);
	 else if(i==6)
		  {
			int p;
			cout<<"\nEnter position ";
			cin>>p;
			root=delete_pos(root,p);
		  }
    /* else if(i==7)
     {
         int v;
         cout<<"\nEnter value ";
         cin>>v;
         root=delete_val(root,v);
     }
     else if(i==8)
        {
            root=reverse_list(root);
            //disp(root);
        }*/
	 else if(i==7)
		  disp(root);
 }
return 0;
}
