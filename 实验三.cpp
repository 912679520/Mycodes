//////#include <iostream>					// Ԥ��������
//////using namespace std;					// ʹ�ñ�׼�����ռ�std
//////// ֱ��������
//////class Point
//////{  private:
//////		int x, y;							// ��������������
//////public:
//////		Point(int a, int b): x(a), y(b){ }		// ���캯��
//////		void Set(int a, int b);				// ��������ֵ
//////		int GetX() const{ return x; }		// ���غ�����
//////		int GetY() const{ return y; }		// ����������
//////};
//////
//////// ֱ�������༰��غ�����ʵ�ֲ���
//////void Point::Set(int a, int b)				// ��������ֵ
//////{   	x = a;							// ������
//////		y = b;							// ������
//////}
//////
//////void Show(const Point &pt)				// ��ʾ����ֵ
//////{ 
//////	cout << pt.GetX() << "  " << pt.GetY() << endl; 
//////}
//////
//////int main(void)							// ������main(void)
//////{
//////	Point a[5] = {Point(0, 0), Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4)};
//////// �ɶ�����ɵ�����
//////	Point *p = a;						// pָ������a
//////	p->Set(5, 9);						// ��������ֵ
//////	a[3].Set(6, 8);					// ��������ֵ
//////	for (int i = 0; i < 5; i++)
//////	{	
//////// ������ʾ�����������ֵ
//////		Show(*p++);    
//////	}
//////
//////    return 0;                    			// ����ֵ0,���ز���ϵͳ
//////}
////
//////2:
////#include <iostream>						// Ԥ��������
////using namespace std;						// ʹ�ñ�׼�����ռ�std
////
////// ������
////class Date
////{
////private:
////	        int month, day, year;						// ������
////public:
////	        Date(int m = 1, int d = 1, int y = 2008);	// ���캯��
////	       // ��Ԫ
////	       friend void Show(const Date &dt);			// ��ʾ����
////};
////
////// �����༰��غ�����ʵ�ֲ���
////Date::Date(int m, int d, int y)				// ��m(��),d(��)��y(��)�������
////{ 
////	   this->month = m;							// ��
////	   this->day = d;					     		// ��
////	   this->year = y;							// ��
////}
////
////void Show(const Date &dt)						// ��ʾ����
////{
////	   cout << dt.month << "/" << dt.day << "/" << dt.year << endl;
////}
////
////int main(void)								// ������main(void)
////{
////	    Date d1(6, 8, 2008), d2(6, 18), d3(5), d4;// �������ڶ���
////	    Show(d1);									// ��ʾd1
////	    Show(d2);									// ��ʾd2
////	    Show(d3);									// ��ʾd3
////	    Show(d4);									// ��ʾd4
////
////    return 0;                    			// ����ֵ0,���ز���ϵͳ
////}
//
//
////3��������ա����������Ҫ���Ծ�̬��Ա��ʹ�÷���������ɳ���
//#include <iostream>				// Ԥ��������
//using namespace std;				// ʹ�ñ�׼�����ռ�std
//
//// ���Ծ�̬��Ա��
//class Test
//{
//private:
//static int count;				// ������
//
//public:
//Test(){ count++; } 			// ���캯��, ʵ�ֶԶ�����м���
//	   static void Show(){ cout << "����" << count << "������!" << endl; }
//	};
//
//int Test::count= 0;					// Ϊ��̬���ݳ�Ա����ֵ
//
//int main()						
//{
//	   Test obj1, obj2, obj3;			// �������
//	   Test::Show();					// ��ʾ������
//
//	   return 0;                    	// ����ֵ0,���ز���ϵͳ
//}
/*
//4��������������еĴ���ʹ�����������С�
#include <iostream>			// Ԥ��������								
using namespace std;			// ʹ�ñ�׼�����ռ�std						
																		
// ���Թ��캯��������������												
class Test															
{																	
public:																
		Test(){ cout << "���캯������" << endl; }
	   ~Test(){ cout << "���캯������" << endl; }
};																	
																		
int main()
	{																	
	  Test obj;					// �������							
	  return 0;// ����ֵ0,���ز���ϵͳ							
	}
	*/
/*
5����д���һ��People���ˣ��ࡣ��������ݳ�Ա������(age)�����(height)������(weight)������(num)��
	��������Ϊ��̬���ݳ�Ա����Ա�����й��캯��(People)����ʳ(Eatting)���˶�(Sporting)��˯��(Sleeping)��
	��ʾ(Show)����ʾ����(ShowNum)�����й��캯������֪��������(a)�����(h)������(w)�������
	��ʳ����ʹ���ؼ�1���˶�����ʹ��߼�1��˯�ߺ���ʹ���䡢��ߡ����ظ���1����ʾ����������ʾ�˵����䡢
	��ߡ����أ���ʾ��������Ϊ��̬��Ա������������ʾ�˵ĸ�������������ĵ�λΪ�꣬��ߵĵ�λΪ���ף�
	���صĵ�λΪ�нҪ���������ݳ�ԱΪprotected����Ȩ�ޣ����г�Ա����Ϊpublic����Ȩ�ޣ�
	����������ͨ������ֱ�ӷ���������г�Ա������*/
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
		cout<<"������"<<num<<endl;
	}

};
int People::num=0;
People::People(int a, int h, double w): age(a), height(h), weight(w)
	{ 
		num++; 
	}						// ����֪��Ϣ�������, ����num���Լ�1

void People::Sleeping()		// ˯��
{
	  age++;							// ˯��ʹ�����1
	  height++;						// ˯��ʹ��߼�1
	  weight++;						// ˯��ʹ���ؼ�1
}

void People::Show()
// ��ʾ�˵���Ϣ
{
	  cout << "��" << num << "����:" << endl;		// ��ʾ�˵����
	  cout << "����:" << age << "��" << endl;		// ��ʾ����
	  cout << "���:" << height << "����" <<endl;	// ��ʾ���
	  cout << "����:" << weight << "��" << endl;// ��ʾ����
	  cout << endl;							// ����
}

int main()							
{
	  People obj1(8, 120, 60);			// �������
	  obj1.Eatting();					// ��ʳ
	  obj1.Sporting();					// �˶�
	  obj1.Sleeping();					// ˯��
	  obj1.Show();						// ��ʾ��Ϣ
	
	  People obj2(18, 170, 108);		// �������
	  obj2.Eatting();					// ��ʳ
	  obj2.Sporting();					// �˶�
	  obj2.Sleeping();					// ˯��
	  obj2.Show();						// ��ʾ��Ϣ
	  People::ShowNum();				// ��ʾ����
	return 0;                    		// ����ֵ0,���ز���ϵͳ
}
*/
/*
*6������һ������ѧ��(Student)����������࣬���ݳ�Ա��������(name)��ѧ��(num)��
	��ѧ�ɼ�(mathScore)��Ӣ��ɼ�(englishScore)������(count)��
	��ѧ�ܳɼ�(mathTotalScore)��Ӣ���ܳɼ�(englishTotalScore)��
	������������Ϊ����Ϊ18���ַ����飬�������ݳ�Ա����Ϊ���ͣ�
	��ѧ�ܳɼ���Ӣ���ܳɼ�������Ϊ��̬���ݳ�Ա��������Ա�������캯����
	��ʾ�������ݺ���(ShowBase)����ʾ��̬���ݺ���(ShowStatic)��
	���й��캯������֪��������(nm)��ѧ��(nu)����ѧ�ɼ�(math)��Ӣ��ɼ�(english)�������
	��ʾ�������ݺ���������ʾѧ����������ѧ�š���ѧ�ɼ���Ӣ��ɼ�����ʾ��̬���ݺ���Ϊ��̬��Ա������
	������ʾ��������ѧ�ܳɼ���Ӣ���ܳɼ���Ҫ���������ݳ�ԱΪprivate����Ȩ�ޣ�
	���г�Ա����Ϊpublic����Ȩ�ޣ����������ж������ɸ�ѧ�����󣬷ֱ���ʾѧ��������Ϣ��
	�Լ���ʾѧ����������ѧ�ܳɼ���Ӣ���ܳɼ�
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
