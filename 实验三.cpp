//////#include <iostream>					// 预处理命令
//////using namespace std;					// 使用标准命名空间std
//////// 直角坐标类
//////class Point
//////{  private:
//////		int x, y;							// 横坐标与纵坐标
//////public:
//////		Point(int a, int b): x(a), y(b){ }		// 构造函数
//////		void Set(int a, int b);				// 设置坐标值
//////		int GetX() const{ return x; }		// 返回横坐标
//////		int GetY() const{ return y; }		// 返回纵坐标
//////};
//////
//////// 直角坐标类及相关函数的实现部分
//////void Point::Set(int a, int b)				// 设置坐标值
//////{   	x = a;							// 横坐标
//////		y = b;							// 纵坐标
//////}
//////
//////void Show(const Point &pt)				// 显示坐标值
//////{ 
//////	cout << pt.GetX() << "  " << pt.GetY() << endl; 
//////}
//////
//////int main(void)							// 主函数main(void)
//////{
//////	Point a[5] = {Point(0, 0), Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4)};
//////// 由对象组成的数组
//////	Point *p = a;						// p指向数组a
//////	p->Set(5, 9);						// 设置坐标值
//////	a[3].Set(6, 8);					// 设置坐标值
//////	for (int i = 0; i < 5; i++)
//////	{	
//////// 依次显示各对象的坐标值
//////		Show(*p++);    
//////	}
//////
//////    return 0;                    			// 返回值0,返回操作系统
//////}
////
//////2:
////#include <iostream>						// 预处理命令
////using namespace std;						// 使用标准命名空间std
////
////// 日期类
////class Date
////{
////private:
////	        int month, day, year;						// 年月日
////public:
////	        Date(int m = 1, int d = 1, int y = 2008);	// 构造函数
////	       // 友元
////	       friend void Show(const Date &dt);			// 显示日期
////};
////
////// 日期类及相关函数的实现部分
////Date::Date(int m, int d, int y)				// 由m(月),d(日)和y(年)构造对象
////{ 
////	   this->month = m;							// 月
////	   this->day = d;					     		// 日
////	   this->year = y;							// 年
////}
////
////void Show(const Date &dt)						// 显示日期
////{
////	   cout << dt.month << "/" << dt.day << "/" << dt.year << endl;
////}
////
////int main(void)								// 主函数main(void)
////{
////	    Date d1(6, 8, 2008), d2(6, 18), d3(5), d4;// 定义日期对象
////	    Show(d1);									// 显示d1
////	    Show(d2);									// 显示d2
////	    Show(d3);									// 显示d3
////	    Show(d4);									// 显示d4
////
////    return 0;                    			// 返回值0,返回操作系统
////}
//
//
////3．程序填空。下面程序主要测试静态成员的使用方法，请完成程序。
//#include <iostream>				// 预处理命令
//using namespace std;				// 使用标准命名空间std
//
//// 测试静态成员类
//class Test
//{
//private:
//static int count;				// 对象数
//
//public:
//Test(){ count++; } 			// 构造函数, 实现对对象进行计数
//	   static void Show(){ cout << "共有" << count << "个对象!" << endl; }
//	};
//
//int Test::count= 0;					// 为静态数据成员赋初值
//
//int main()						
//{
//	   Test obj1, obj2, obj3;			// 定义对象
//	   Test::Show();					// 显示对象数
//
//	   return 0;                    	// 返回值0,返回操作系统
//}
/*
//4．改正下面程序中的错误，使其能正常运行。
#include <iostream>			// 预处理命令								
using namespace std;			// 使用标准命名空间std						
																		
// 测试构造函数与析构函数类												
class Test															
{																	
public:																
		Test(){ cout << "构造函数运行" << endl; }
	   ~Test(){ cout << "析造函数运行" << endl; }
};																	
																		
int main()
	{																	
	  Test obj;					// 定义对象							
	  return 0;// 返回值0,返回操作系统							
	}
	*/
/*
5．编写设计一个People（人）类。该类的数据成员有年龄(age)、身高(height)、体重(weight)和人数(num)，
	其中人数为静态数据成员，成员函数有构造函数(People)、进食(Eatting)、运动(Sporting)、睡眠(Sleeping)、
	显示(Show)和显示人数(ShowNum)。其中构造函数由已知参数年龄(a)、身高(h)和体重(w)构造对象，
	进食函数使体重加1，运动函数使身高加1，睡眠函数使年龄、身高、体重各加1，显示函数用于显示人的年龄、
	身高、体重，显示人数函数为静态成员函数，用于显示人的个数。假设年龄的单位为岁，身高的单位为厘米，
	体重的单位为市斤，要求所有数据成员为protected访问权限，所有成员函数为public访问权限，
	在主函数中通过对象直接访问类的所有成员函数。*/
/*
#include<iostream>
using namespace std;
class People
{
protected:
	int age;
	int height;
	double weight;
	static int num;
public:
	People(int a,int h,double w);
	void Eatting()
		{
			weight++;
		}
	void Sporting()
	{
		height++;
	}
	void Sleeping();
	void Show();
	static void ShowNum()
	{
		cout<<"人数："<<num<<endl;
	}

};
int People::num=0;
People::People(int a, int h, double w): age(a), height(h), weight(w)
	{ 
		num++; 
	}						// 由已知信息构造对象, 人数num将自加1

void People::Sleeping()		// 睡眠
{
	  age++;							// 睡眠使年龄加1
	  height++;						// 睡眠使身高加1
	  weight++;						// 睡眠使体重加1
}

void People::Show()
// 显示人的信息
{
	  cout << "第" << num << "个人:" << endl;		// 显示人的序号
	  cout << "年龄:" << age << "岁" << endl;		// 显示年龄
	  cout << "身高:" << height << "厘米" <<endl;	// 显示身高
	  cout << "体重:" << weight << "斤" << endl;// 显示体重
	  cout << endl;							// 换行
}

int main()							
{
	  People obj1(8, 120, 60);			// 定义对象
	  obj1.Eatting();					// 进食
	  obj1.Sporting();					// 运动
	  obj1.Sleeping();					// 睡眠
	  obj1.Show();						// 显示信息
	
	  People obj2(18, 170, 108);		// 定义对象
	  obj2.Eatting();					// 进食
	  obj2.Sporting();					// 运动
	  obj2.Sleeping();					// 睡眠
	  obj2.Show();						// 显示信息
	  People::ShowNum();				// 显示人数
	return 0;                    		// 返回值0,返回操作系统
}
*/
/*
*6．定义一个描述学生(Student)基本情况的类，数据成员包括姓名(name)、学号(num)、
	数学成绩(mathScore)、英语成绩(englishScore)、人数(count)、
	数学总成绩(mathTotalScore)和英语总成绩(englishTotalScore)。
	其中姓名定义为长度为18的字符数组，其它数据成员类型为整型，
	数学总成绩、英语总成绩和人数为静态数据成员，函数成员包括构造函数、
	显示基本数据函数(ShowBase)和显示静态数据函数(ShowStatic)，
	其中构造函数由已知参数姓名(nm)、学号(nu)、数学成绩(math)和英语成绩(english)构造对象，
	显示基本数据函数用于显示学生的姓名、学号、数学成绩、英语成绩，显示静态数据函数为静态成员函数，
	用于显示人数，数学总成绩，英语总成绩；要求所有数据成员为private访问权限，
	所有成员函数为public访问权限，在主函数中定义若干个学生对象，分别显示学生基本信息，
	以及显示学生人数，数学总成绩与英语总成绩
	*/
#include<iostream>
using namespace std;
class Student
{
private:
	char name[18];
	int num;
	int mathScore;
	int Englishscore;
	static int count;
	static int mathTotalScore;
	static int EnglishTotalscore;
public:
	Student(char *nm,int nu,int math,int english):num(nu),mathScore(math),Englishscore(english)
	{
		strcpy(name,nm);
		count++;
		mathTotalScore+=mathScore;
		EnglishTotalscore+=Englishscore;
	}
	void ShowBase()
	{
		cout << name << "  " << num << "  " << mathScore << "  " << Englishscore << endl ;
	}
	static void ShowStatic()
	{
		cout << count << "  " << mathTotalScore << "  " << EnglishTotalscore << endl;
	}
};
int Student::mathTotalScore=0;
int Student::EnglishTotalscore=0;
int Student::count=0;
int main()
{
	Student s("liang",1,60,60),t("xuan",2,60,60);
	s.ShowBase();
	t.ShowBase();
	Student::ShowStatic();
	return 0;
}
