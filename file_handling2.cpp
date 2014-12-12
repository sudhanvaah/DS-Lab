//Program to store student records in a file and display them
#include<stdio.h>
#include<iostream>
using namespace std;
struct student
{
    char usn[15],name[20];
    int age;
};
main()
{
    FILE *fp1;
    student s;
    char f1[20],ch;
    int i,n;
    cout<<"\nEnter number of students ";
    cin>>n;
    cout<<"\nEnter file to which data must be written ";
    cin>>f1;
    fp1=fopen(f1,"w+");
    if(fp1==NULL)
    {
       cout<<"\nInvalid filename.";
       return 0;
    }
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter USN, name and age of student "<<i<<" ";
        cin>>s.usn>>s.name>>s.age;
        fprintf(fp1,"%s %s %d ",s.usn,s.name,(s.age));
    }
    rewind(fp1);
    cout<<"\nStudent details:\n ";
    for(i=1;i<=n;i++)
    {
        fscanf(fp1,"%s %s %d",s.usn,s.name,&(s.age));
        cout<<"\n"<<i<<". USN: "<<s.usn<<"\n   Name: "<<s.name<<"\n   Age: "<<s.age;
    }
    return 0;
}
