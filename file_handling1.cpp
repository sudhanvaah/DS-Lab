//Program to copy data from one file to another
#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
    FILE *fp1,*fp2;
    char f1[20],f2[20],ch;
    cout<<"\nEnter file from which data must be copied ";
    cin>>f1;
    fp1=fopen(f1,"r");
    if(fp1==NULL)
    {
       cout<<"\nInvalid filename.";
       return 0;
    }
    cout<<"\nEnter file into which data must be copied ";
    cin>>f2;
    fp2=fopen(f2,"w");
    ch=getc(fp1);
    while(ch!=EOF)
        {
            putc(ch,fp2);
            ch=getc(fp1);
        }
    cout<<"\nData copied successfully.";
    fclose(fp1);
    fclose(fp2);
    return 0;
}
