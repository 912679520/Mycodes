#include<iostream>
#include<string.h>
using namespace std;
class String
{
public:
	String()
	{
		p = NULL;
	}
	String(char *str);
	friend String operator + (String &string1, String &string2);
	friend String operator + (String &string1, char *arr);
	friend String operator + (char *arr, String &string1);
	bool operator < (String &str);
	bool operator != (String &str);
	~String()
	{
		delete []p;
	}
	void display();

private:
	char *p;
	int len;
	friend std::ostream& operator<<(std::ostream, String &);
};

String::String(char *str)
{
	p = str;
}

String operator + (String &str1, String &str2)
{
	String str3;
	str3.len =str1.len + str2.len;
	str3.p = new char [str3.len+1];
	strcpy(str3.p, str1.p);
	strcat(str3.p, str2.p);
	return str3;
}

String operator + (String &str1,char *arr)
{
	 String str3;
	 str3.len = str1.len + sizeof(arr)/sizeof(arr[0]);
	 str3.p = new char [str3.len+1];
	 strcpy(str3.p, arr);
	 strcat(str3.p, arr);
}

bool  operator < (String &str1, String &str2)
{
	if(strcmp(str1.p,str2.p) < 0)
	{
		return true;
	}

}

bool operator != (String &str1,String &str2)
{
	if(strcmp(str1.p,str2.p) != 0)
	{
		return true;
	}

}

std::ostream& operator<<(std::ostream& cout,const String& str)
{
	out << 
}

int main()
{
	String str1("hello");
	String str2 = ("world");
	String str3 = str1 + str2;
	
	str3 = str1 + "hi";
	str3 = "hi" + str2;

	if(str1 < str2)
	{ 
		std::cout << str1 << std::endl;
	}
	if(str1!=str2)
	{
		std::cout << str2 << std::endl;
	}
	char a = str1[0];
	return 0;
}
