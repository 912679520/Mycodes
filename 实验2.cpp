//2����д��������ԭ��Ϊ��void index(int a[], int n,int & sub)��
//���ܣ�s�ڴ�СΪn������a�У�����ĳ����ub�����ҵ�������Ӧ����Ԫ�ص��±긳��sub��
//��û�ҵ�����-1����sub��������������ͨ���ж�sub��ֵ���ж��������Ƿ��и�����
//�����sub���������͵Ĳ��������𷵻�ֵ�����á�
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
		cout<<"�и���,��λ�������"<<tmp+1<<"λ"<<endl;
	return 0;
}