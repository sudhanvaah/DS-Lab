#include<fstream>
#include<iostream>
using namespace std;
class product
{
    public:
    int pno;
    char name[20];
    float price;
};
int main()
{
        product p[3],q;
        ofstream fout("/home/3c/product.bin");
        for(int i=0;i<3;i++)
        {
        cout<<"\nEnter product number ";
        cin>>p[i].pno;
        cout<<"\nEnter product name ";
        cin>>p[i].name;
        cout<<"\nEnter product price ";
        cin>>p[i].price;
        fout.write((char*)&(p[i]),sizeof(product));
        }
	fout.close();
	ifstream fin("/home/3c/product.bin");
	for(int i=0;i<3;i++)
	{
    fin.read((char*)&q,sizeof(product));
	cout<<"\n"<<i+1<<". Product number: "<<q.pno<<"\nProduct name: "<<q.name<<"\nPrice: "<<q.price;
	}
	return 0;
}
