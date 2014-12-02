////Expression tree
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
using namespace std;
struct node
{
    char data;
    node *l,*r;
};
typedef node * NODE;
NODE getnode(char ch)
{
    NODE x=(NODE)malloc(sizeof(node));
    x->data=ch;
    x->l=x->r=NULL;
    return x;
}
NODE maketree(char post[])
{
    NODE temp,st[20];
    int i,j;
    char sy;
    for(i=0,j=0;post[i]!='\0';i++)
    {
        sy=post[i];
        temp=getnode(sy);
        if(isdigit(sy))
            st[j++]=temp;
        else
        {
            temp->r=st[--j];
            temp->l=st[--j];
            st[j++]=temp;
        }
    }
    return st[--j];
}

float eval(NODE tree)
{
    float num;
    switch(tree->data)
    {
        case '+':return(eval(tree->l)+eval(tree->r));
        case '-':return(eval(tree->l)-eval(tree->r));
        case '*':return(eval(tree->l)*eval(tree->r));
        case '/':return(eval(tree->l)/eval(tree->r));
        case '$':
        case '^': return(pow(eval(tree->l),eval(tree->r)));
        default:  return (tree->data-'0');
    }
}
main()
{
    NODE tree=NULL;
    char postf[30];
    float f = 0;
    cout<<"\nEnter a postfix expression \n";
    cin>>postf;
    tree=maketree(postf);
    f = eval(tree);
    cout<<"\nAnswer = "<<f;
}
