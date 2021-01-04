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
//该程序让用户输入圆的半径Radius，
//输出圆的周长Perimeter和面积Area
#include<iostream>
#include<cmath>
using namespace std;
const double PI=3.14159;//定义一个不可修改的常量PI  #define PI 3.14159
int main()
{	
	int radius;
	double perimeter,area;
	cout<<"请输入半径:";
	cin>>radius;
	perimeter=2*PI*radius;  //周长=2πR
	area=PI*pow(radius,2);	//面积=πR2  pow求的是radius n次方 
	cout<<"周长是："<<perimeter<<endl;
	cout<<"面积是："<<area<<endl; 
	return 0;	
}
*/
//4:编写一个计算矩形面积的程序
/*
#include<iostream>
using namespace std;
int main()
{	
	int l;
	int breadth;
	int area;
	cout<<"请输入长：";
	cin>>l;
	cout<<"请输入宽：";
	cin>>breadth;
	area=l*breadth;
	cout<<"面积是："<<area<<endl;
	return 0;
} 
*/
//5、使用梯形法计算定积分。
//被积函数为f(x) = sin(x)+e^x，
//积分区间[0,1],积分区间被等分200份。
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
//6、要求实现输入两个整数，
//将它们交换后输出。
//方法一：交换两个整数，一般方法是用一个中间变量，
//经过几次赋值实现。
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
/*方法二：采用按位异或方法，
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int v1,v2;											
	cin>>a>>b;
	v1=a; v2=b;  //原v1为a,v2为b  				例 a=1，b=2； v1=0001     	v2=0010
	v1=v1^ v2;   //即V1为a^ b，V2保持不变							v1  0011  3
	v2=v1^ v2;   //即v2=a^ b^ b=a									v2   0001   1
	v1=v1^ v2;   //即v1=a^ b^ a=b，交换成功							v1   0010  2
	cout<<v1<<" "<<v2<<endl;
	return 0;
}
*/
//编写计算阶乘n!的程序
/*
//7：递归： 
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
//8、编写程序求斐波那契数列的第n项和前n项之和
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
//9、输入一个整数，判断数的奇偶性后输出结果
//方法一：判断一个数是否为偶数，只要判断它是否能被2整除。
//若能整除，则为偶数；否则，为奇数
/*
#include<iostream>
using namespace std;
int main()
{	
	int n;
	cin>>n;
	if(n%2==0)
		cout<<"n是偶数"<<endl;
	else
		cout<<"n是奇数"<<endl; 
	return 0;
}
*/
//方法二：判断一个数的奇偶，只需判断最后一位，在二进制表示形式中，奇数的末位为1，偶数末位为0。
//可以用整数n与1进行按位与运算：n&1为非0（真），则是奇数，为0（假），则是偶数
/*
#include<iostream>
using namespace std;
int main()
{	
	int n;
	cin>>n;
	if(n&1!=0)
		cout<<"n是奇数"<<endl;
	else
		cout<<"n是偶数"<<endl;	
	return 0;
} 
*/
//10:计算工资
//（1）：用循环
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
//（3）循环在用户输入的工作时间为0时结束；
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
//12、用数组来处理求斐波那契数列的第n项和前n项之和。
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
//13、打印杨辉三角形（要求打印十行）。
/*
#include<iostream>
using namespace std;
int main()
{
	int arr[100][100];
	int n;
	scanf("%d",&n);//打印的行数
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
//14、编写一函数，求给定矩阵的转置。
//??????????????????????//
//15、编写一个字符串处理函数，将一个字符串中的所有大写字母转换为对应的小写字母。
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
//16、掌握各种运算符。
/*
#include <iostream> 
using namespace std;
int main()
{
	char c1='a', c2='b', c3='c';
	int i1=10, i2=20, i3=30;
	double d1=0.1, d2=0.2, d3=0.4;
	//数据类型说明符x;
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
//18、求a+aa+aaa+aaaa+... ...+aa...a（n个），其中a为1～9之间的整数。
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
//19、找出2~10000之内的所有完全数。所谓完全数，即其因子之和正好等于该数本身。
//如6=1+2+3，28=1+2+4+7+14，所以6，28都是完全数。
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
//20、由0到4五个数字，组成五位数，每个数字用一次，
//但十位和百位不能为3（当然万位不能为0），输出所有可能的五位数。
#include<iostream>
using namespace std;
int main()
{
	int a[5]={0,1,2,3,4};//个位
	int b[4]={0,1,2,4};//十位
	int c[4]={0,1,2,4};//百位
	int d[5]={0,1,2,3,4};//千位
	int e[4]={1,2,3,4};//万位
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
////删除多余空格
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
/*寻找最大数；
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
//八皇后：八行八列，同行，同列，45度，135度都不可以
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
//将n转换为radix进制的字符串保存到str中
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
