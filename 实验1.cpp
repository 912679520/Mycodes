/*
#include <iostream>
using std::cout ; 
using std::endl ;
int main() 
{
	cout << "Hello,World!"<< endl ;
	return 0;
}
*/


/* 
//�ó������û�����Բ�İ뾶Radius��
//���Բ���ܳ�Perimeter�����Area
#include<iostream>
#include<cmath>
using namespace std;
const double PI=3.14159;//����һ�������޸ĵĳ���PI  #define PI 3.14159
int main()
{	
	int radius;
	double perimeter,area;
	cout<<"������뾶:";
	cin>>radius;
	perimeter=2*PI*radius;  //�ܳ�=2��R
	area=PI*pow(radius,2);	//���=��R2  pow�����radius n�η� 
	cout<<"�ܳ��ǣ�"<<perimeter<<endl;
	cout<<"����ǣ�"<<area<<endl; 
	return 0;	
}
*/
//4:��дһ�������������ĳ���
/*
#include<iostream>
using namespace std;
int main()
{	
	int l;
	int breadth;
	int area;
	cout<<"�����볤��";
	cin>>l;
	cout<<"�������";
	cin>>breadth;
	area=l*breadth;
	cout<<"����ǣ�"<<area<<endl;
	return 0;
} 
*/
//5��ʹ�����η����㶨���֡�
//��������Ϊf(x) = sin(x)+e^x��
//��������[0,1],�������䱻�ȷ�200�ݡ�
/*
#include<iostream>
#include<cmath>
using namespace std;
void Getsin(int a,int b)
{
	int i,n;
	float d=0.01,s=0;
	n=(b-a)/d;
	for(i=0;i<n;i++)
	{
		s+=(sin(a+d*i)+sin(a+d*(i+1)))*d/2.0;
	}
	printf("%f",s);
}
void Getex()
{
	
	
}

int main()
{
	Getsin(0,1);
	return 0;
}
*/
//6��Ҫ��ʵ����������������
//�����ǽ����������
//����һ����������������һ�㷽������һ���м������
//�������θ�ֵʵ�֡�
/*
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int tmp;
	cin>>a>>b;
	tmp=a;
	a=b;
	b=tmp;
	cout<<a<<" "<<b<<endl;
	return 0;
}*/
/*�����������ð�λ��򷽷���
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int v1,v2;											
	cin>>a>>b;
	v1=a; v2=b;  //ԭv1Ϊa,v2Ϊb  				�� a=1��b=2�� v1=0001     	v2=0010
	v1=v1^ v2;   //��V1Ϊa^ b��V2���ֲ���							v1  0011  3
	v2=v1^ v2;   //��v2=a^ b^ b=a									v2   0001   1
	v1=v1^ v2;   //��v1=a^ b^ a=b�������ɹ�							v1   0010  2
	cout<<v1<<" "<<v2<<endl;
	return 0;
}
*/
//��д����׳�n!�ĳ���
/*
//7���ݹ飺 
#include<iostream>
using namespace std;
int Getn(int n)
{
	if(n==0|| n==1)
		return 1;
	else 
		return Getn(n-1)*n;
} 
int main()
{
	int n;
	cin>>n;
	cout<<Getn(n)<<endl;
	return 0;
}
*/
//8����д������쳲��������еĵ�n���ǰn��֮��
/*
#include<iostream>
using namespace std;
int Getn(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return Getn(n)==Getn(n-1)+Getn(n-2);
}

int main()
{
	int n;
	cin>>n;
	cout<<Getn(5)<<endl;
	return 0;
}
*/
//9������һ���������ж�������ż�Ժ�������
//����һ���ж�һ�����Ƿ�Ϊż����ֻҪ�ж����Ƿ��ܱ�2������
//������������Ϊż��������Ϊ����
/*
#include<iostream>
using namespace std;
int main()
{	
	int n;
	cin>>n;
	if(n%2==0)
		cout<<"n��ż��"<<endl;
	else
		cout<<"n������"<<endl; 
	return 0;
}
*/
//���������ж�һ��������ż��ֻ���ж����һλ���ڶ����Ʊ�ʾ��ʽ�У�������ĩλΪ1��ż��ĩλΪ0��
//����������n��1���а�λ�����㣺n&1Ϊ��0���棩������������Ϊ0���٣�������ż��
/*
#include<iostream>
using namespace std;
int main()
{	
	int n;
	cin>>n;
	if(n&1!=0)
		cout<<"n������"<<endl;
	else
		cout<<"n��ż��"<<endl;	
	return 0;
} 
*/
//10:���㹤��
//��1������ѭ��
/*
#include<iostream>
using namespace std;
int main() 
{
	int min;
	double gz;
	double sum;
	while(cin>>min>>gz && min!=0 && gz!=0)
	{
		
		if(min<=40)
			sum=min*gz;
		else if(min>40 && min<=50)
			sum=(min-40)*1.5*gz+40*gz;
		else if(min>50)
			sum=(min-50)*3*gz+10*1.5*gz+40*gz;		
			cout<<sum<<endl;
	}
	return 0;
}

*/
/*
#include<iostream>
using namespace std;
int main() 
{
	int min;
	double gz;
	double sum;
	while(cout<<"Please input employee's work time and wage_per_hour:"<<endl && cin>>min>>gz&&min!=0 && gz!=0)
	{
		
		if(min<=40)
			sum=min*gz;
		else if(min>40 && min<=50)
			sum=(min-40)*1.5*gz+40*gz;
		else if(min>50)
			sum=(min-50)*3*gz+10*1.5*gz+40*gz;	
			cout<<"The employee's wage :"<<endl;	
			cout<<sum<<endl;
	}
	return 0;
}
*/
//��3��ѭ�����û�����Ĺ���ʱ��Ϊ0ʱ������
/*
#include<iostream>
using namespace std;
int main() 
{
	int min;
	double gz;
	double sum;
	while(cin>>min>>gz && min!=0)
	{
		
		if(min<=40)
			sum=min*gz;
		else if(min>40 && min<=50)
			sum=(min-40)*1.5*gz+40*gz;
		else if(min>50)
			sum=(min-50)*3*gz+10*1.5*gz+40*gz;		
			cout<<sum<<endl;
	}
	return 0;
}
*/
//11:
/*
#include <iostream>
using namespace std;
int main()
{	cout << "char length:" << sizeof( char ) << endl;					// 	1
	cout << "int length:" << sizeof( int ) << endl;						//	4
	cout << "long length:" << sizeof( long ) << endl;					//	4
	cout << "float length:" << sizeof( float ) << endl;					//	4
	cout << "double length:" << sizeof( double ) << endl;				// 	8
	cout << "long double length:" << sizeof( long double ) << endl;		//	12 || 16
	cout << "char* length:" << sizeof( char* ) << endl;					//	4	||	8
	cout << "int* length:" << sizeof( int* ) << endl;					//	4
	cout << "long* length:" << sizeof( long* ) << endl;					//	4
	cout << "float* length:" << sizeof( float* ) << endl;				//	4
	cout << "double* length:" << sizeof( double* ) << endl;				//	4
	cout << "long double* length:" << sizeof( long double* ) << endl;	//	4
	cout << "void* length:" << sizeof( void* ) << endl;
	return 0;   
}
*/
//12����������������쳲��������еĵ�n���ǰn��֮�͡�
/*
#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	 arr[1]=1;
	 arr[0]=1;
	int n;
	int sum=0;
	scanf("%d",&n);
	for(int i=2;i<n;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
		
	}
	cout<<arr[n-1]<<endl;
	for(int j=0;j<n;j++)
	{
		sum+=arr[j];
	}
	cout<<sum<<endl;
	return 0;
}
*/
//13����ӡ��������Σ�Ҫ���ӡʮ�У���
/*
#include<iostream>
using namespace std;
int main()
{
	int arr[100][100];
	int n;
	scanf("%d",&n);//��ӡ������
	for(int i=0;i<n;i++)
	{
			arr[i][i]=1;
			arr[i][0]=1;
	}
	for(int i=2;i<n;i++)
	{
		for(int j=1;j<i;j++)
		{
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			
			{
				cout<<arr[i][j]<<"   ";
			}

		}
		cout<<endl;
	}
	return 0;
}
*/
//14����дһ����������������ת�á�
//??????????????????????//
//15����дһ���ַ�������������һ���ַ����е����д�д��ĸת��Ϊ��Ӧ��Сд��ĸ��
/*
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char arr[10];
	gets(arr);
	for(int i=0;i<strlen(arr);i++)
	{
		if(arr[i]>='A' && arr[i]<='Z');	
		arr[i]+=32;
	}
	puts(arr);
	return 0;
}
*/
//16�����ո����������
/*
#include <iostream> 
using namespace std;
int main()
{
	char c1='a', c2='b', c3='c';
	int i1=10, i2=20, i3=30;
	double d1=0.1, d2=0.2, d3=0.4;
	//��������˵����x;
	double x;
	//x=c1+i2*i3/i2%i1;//	a	x=97
	//x=c1+i2*i3/i2%i1;		b	x=97
	//x=i2-- * ++i3;		c	x=620
	//x=i1>i2>i3<d1<d2<d3;	d	x=1
	//x=(c1=i2*i3)!=(i2%i1);	e   x=1
	//x=d1>d2||i1==i2;			f  x=0
	//x=c1>i1?i1:c2;				g	x=10
	//x=0?1:2?0:0?3:4;				h	x=0
	//x= i1+=i2*=i3;				i	x=610
	//x=i3=(i1=1,i2--);				j	x=20
	//x=i1=(c1,c2,c3);				k	x=99
	//x=!i1&&i2--;					l x=0
	cout<<"x="<<x<<endl;
	return 0;
}
*/
//18����a+aa+aaa+aaaa+... ...+aa...a��n����������aΪ1��9֮���������
/*
#include<iostream>
using namespace std;
int GetA(int a,int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=i;j++)
		{
			tmp=tmp*10+a;
		}
		sum+=tmp;
	}
	return sum;
}

int main()
{
	cout<<GetA(1,3)<<endl;
	cout<<GetA(5,3)<<endl;
	return 0;
}
*/
//19���ҳ�2~10000֮�ڵ�������ȫ������ν��ȫ������������֮�����õ��ڸ�������
//��6=1+2+3��28=1+2+4+7+14������6��28������ȫ����
/*
#include<iostream>
using namespace std;
int main()
{
	
	for(int i=2;i<10000;i++)
	{
		int sum=0;
		for(int j=1;j<i/2+1;j++)
		{
			if(i%j==0 && i!=j)
			{
				sum+=j;	
				
			}
		}
		if(sum==i)
			printf("%d\n",i);
	}
	return 0;
}
*/
//20����0��4������֣������λ����ÿ��������һ�Σ�
//��ʮλ�Ͱ�λ����Ϊ3����Ȼ��λ����Ϊ0����������п��ܵ���λ����
#include<iostream>
using namespace std;
int main()
{
	int a[5]={0,1,2,3,4};//��λ
	int b[4]={0,1,2,4};//ʮλ
	int c[4]={0,1,2,4};//��λ
	int d[5]={0,1,2,3,4};//ǧλ
	int e[4]={1,2,3,4};//��λ
	int sum=0;
	for(int e1=0;e1<4;e1++)
		for(int d1=0;d1<5;d1++)
			for(int c1=0;c1<4;c1++)
				for(int b1=0;b1<4;b1++)
					for(int a1=0;a1<4;a1++)
					{
						if(a[a1]!=b[b1]&&a[a1]!=c[c1]&&a[a1]!=d[d1]&&a[a1]!=e[e1]&&b[b1]!=c[c1]&&b[b1]!=d[d1]&&b[b1]!=e[e1]&&c[c1]!=d[d1]&&c[c1]!=e[e1]&&d[d1]!=e[e1])
						{
							sum= e[e1]*10000+d[d1]*1000+c[c1]*100+b[b1]*10+a[a1];
							cout<<sum<<' ';
						}	
						
					}

}






//#include<stdio.h>
//#include<string.h>
////ɾ������ո�
//void DelBlank(char *str)
//{
//	char string;
//	int space=0;
//	while((string=getchar())!=EOF)
//	{
//		if(string==' ')
//		{
//			if(space==0)
//			{
//				space=1;
//				putchar(string);
//			}
//		}
//		if(string!=' ')
//		{
//			space=0;
//			putchar(string);
//		}
//	}
//}
//int main()
//{
//	//DelBlank(str);
//	return 0;
//}
/*Ѱ���������
#include<stdio.h>
#include<stdarg.h>
int max_list(int a,...)
{
	int max=a;
	int tmp=a;
	va_list list;
	va_start(list,a);
	while(tmp>=0)
	{
		tmp=va_arg(list,int);
		if(tmp>max)
		{
			max=tmp;
		}
	}
	return max;
	va_end(list);
}

int main()
{
	printf("%d\n",max_list(1,3,4,5,6,2,-1));
	return 0;
}
*/
//#include<stdio.h>
//void may()
//{
//	int a=0;
//	int b=0;
//	int c=0;
//	int d=0;
//	int e=0;
//	while(15*a+23*b+29*c+d*41+e*67!=1808)
//	{
//		while(23*b+29*c+d*41+e*67!=1808)
//			while(29*c+d*41+e*67!=1808)
//				while(d*41+e*67!=1808)
//					while(e*67!=1808)
//						while(a*15!=1808)
//							while(23*b!=1808)
//								while(29*c!=1808)
//
//
//
//	}
//
//
//	
//}
//
//
//int main()
//{
//	may();
//	return 0;
//}
//�˻ʺ󣺰��а��У�ͬ�У�ͬ�У�45�ȣ�135�ȶ�������
/*
#include<stdio.h>
int queen()
{
	int queen[8][8];
	int count=0;  
	for(int i=0;i<8;i++)
	{
		queen[0][i]=0;
		for(int j=0;j<8;j++)
		{

		}

	}
	 

}

int main()
{
	
	return 0;
}
*/
//��nת��Ϊradix���Ƶ��ַ������浽str��
//2<=radix<=36
/*
#include<stdio.h>
void Myitoa(char *str,int n,int radix)
{
	while(n!=0)
	{
		n%=radix;
		n/=radix;
		
	}


}

int main()
{

	return 0;
}
*/
//#include<iostream>
//using namespace std;
//int Getn(int n)
//{
//	if(n==1 || n==2)
//		return 1;
//	else
//		return Getn(n-1)+Getn(n-2);
//}
//
//int main()
//{
//	int n;
//	cin>>n;
//	cout<<Getn(n)<<endl;
//	return 0;
//}
