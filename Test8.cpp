
#if 0
#include<iostream>
#include<cstring>
using namespace std;

class String
{
	struct StrNode
	{
		int len;		//字符串长度
		int size;		//记录柔性数组的大小
		int ref;		//引用计数
		char data[];	//柔性数组
	};
private:
	StrNode* str;
public:
	String(const char* s = nullptr) :str(nullptr)
	{
		if (s != nullptr)
		{
			int len = strlen(s);
			str = (StrNode*)malloc(sizeof(StrNode) + 2 * (len + 1));
			if (str == nullptr) exit(EXIT_FAILURE);
			str->len = len;
			str->size = 2 * (len + 1);
			str->ref = 1;
			strcpy_s(str->data, len + 1, s);
		}
	}
	~String()
	{
		if (str != nullptr && --str->ref == 0)
		{
			free(str);
		}
		str = nullptr;
	}
	String(const String &s):str(s.str)
	{
		if (str != nullptr)
		{
			str->ref += 1;
		}
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			if (this->str != nullptr && --this->str->ref == 0)
			{
				free(str);
			}
			str = s.str;
			if (str != nullptr)
			{
				str->ref += 1;
			}
		}
		return *this;
	}
	String& operator+=(const String& s)
	{
		if (this->str == nullptr)
		{
			this->str = s.str;
			if (this->str != nullptr)
			{
				this->str->ref += 1;
			}
		}
		else if (this->str != nullptr && this->str->ref == 1)
		{
			int dist = this->str->size - this->str->len - 1;
			if (dist >= s.str->len)
			{
				strcat_s(this->str->data, this->str->size, s.str->data);
			}
			else
			{

			}
		}
		else
		{
			StrNode* sp = this->str;
			this->str->ref -= 1;
			this->str = nullptr;
			int total = sp->len + s.str->len + 1;
			str = (StrNode*)malloc(sizeof(StrNode) + 2 * total);
			str->len = total - 1;
			str->size = 2 * total;
			str->ref = 1;
			strcpy_s(str->data, str->size, sp->data);
			strcat_s(str->data, str->size, s.str->data);
		}
		return *this;
	}
};

int main()
{
	String s1("yhpinghello");
	String s2("tulun");
	String s3("hello");
	s1 += s2;
	//s1 = s2 + s3;
	return 0;
}
#endif
