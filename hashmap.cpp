#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

//int main()
//{
//	//���
//	unordered_map<int, string> map = { {5, "����"}, {6, "����"} };
//	map[2] = "����";
//	map.insert(pair<int, string>(3, "�ɶ�"));
//
//	//���� + ������
//	auto it1 = map.begin();
//	while (it1 != map.end())
//	{
//		cout << it1->first << " " << it1->second << endl;
//		++it1;
//	}
//
//	//����Ԫ��
//	auto it = map.find(2);
//	if (it != map.end())
//	{
//		cout << endl << it->first << it->second << endl;
//	}
//	//system("pause");
//	return 0;
//}