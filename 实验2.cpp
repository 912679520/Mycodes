//2、编写函数，其原型为：void index(int a[], int n,int & sub)。
//功能：s在大小为n的数组a中，查找某个数ub，若找到，将对应数组元素的下标赋给sub，
//若没找到，将-1赋给sub，在主调函数中通过判断sub的值来判断数组中是否有该数。
//在这里，sub是引用类型的参数，但起返回值的作用。
#include<iostream>
#include<string.h>
using namespace std;
int index(int a[], int n,int &sub)
{
	int itmp=sub;
	sub=-1;
	for(int i=0;i<n;i++)
	{
		if(itmp==a[i])	
		{
			sub=i;
		}	
	}
		return sub;
}
int main()
{
	int a[]={23,54,65,487,465};
	int n=sizeof(a)/sizeof(0);
	int sub;
	int tmp;
	cin>>sub;
	tmp=index(a,5,sub);
	if(tmp!=-1)
		cout<<"有该数,且位于数组第"<<tmp+1<<"位"<<endl;
	return 0;
}