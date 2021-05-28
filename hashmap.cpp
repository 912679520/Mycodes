#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

//int main()
//{
//	//添加
//	unordered_map<int, string> map = { {5, "长大"}, {6, "礼物"} };
//	map[2] = "李四";
//	map.insert(pair<int, string>(3, "成二"));
//
//	//遍历 + 迭代器
//	auto it1 = map.begin();
//	while (it1 != map.end())
//	{
//		cout << it1->first << " " << it1->second << endl;
//		++it1;
//	}
//
//	//查找元素
//	auto it = map.find(2);
//	if (it != map.end())
//	{
//		cout << endl << it->first << it->second << endl;
//	}
//	//system("pause");
//	return 0;
//}