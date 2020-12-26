//ÅÅÐò×Ö·û´®
#include "iostream"
#include<string.h>

using namespace std;

void swap(char *a[])
{
	char *temp;
	for(int i =0; i<9; i++)
	{
		for (int j=0;j<9;j++)
		{
			if (strcmp(*(a+j),*(a+j+1))>0)
			{
				temp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=temp;
			}
		}
	}
}
int main()
{
	void swap(char *[]);
	char *p[10];
	char str[10][6];
	cout<<"ÊäÈëÒªÅÅÐòµÄ×Ö·û´® "<<endl;
	for (int i=0;i<10;i++)
	{
		p[i] = str[i];
	}

	
	for (int j=0;j<10;j++)
	{
		cin>>p[j];
	}
	swap(p);
	cout<<"output:"<<endl;
	for(int i=0; i<10; i++)
	{
		cout<<p[i]<<endl;
	}


	return 0;
}