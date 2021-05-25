#include<iostream>
#include<unordered_map>
#include<ctime>
#include<cstdlib>

using namespace std;

/*
	˼·��ʹ��������ϣ��
	������A��һ����������һ����key A�� value 0
	�ڶ�����key 0�� value A
	����ڶ����е�key������value

	insert��������ͬʱ��
	delete��ֱ��ɾ���ж�����������
	�����һ������Ҫɾ����λ�ã����ò�����

*/

class Pool
{
private:
	unordered_map<string, int> keyIndexMap;
	unordered_map<int, string> indexKeyMap;
	int size;
public:
	Pool()
	{
		size = 0;
	}

	void add(string key)
	{
		keyIndexMap.insert(make_pair(key, size));
		indexKeyMap.insert(make_pair(size, key));
		size++;
	}

	void Delete(string key)
	{
		if (!keyIndexMap.count(key)) return;
		//Ҫɾ���ĵ�һ����key������
		int deleteIndex = keyIndexMap.find(key)->second;
		//�õ��ڶ������key
		int lastIndex = --size;
		//���ڶ��������һ��ֵ����Ҫɾ��λ��
		string lastKey = indexKeyMap.find(lastIndex)->second;
		indexKeyMap[deleteIndex] = lastKey;
		indexKeyMap.erase(lastIndex);

		//��һ�������һ��ֵ����Ҫɾ��λ��
		keyIndexMap[lastKey] = deleteIndex;
		keyIndexMap.erase(key);
	}
	string getRandom()
	{
		srand((unsigned int)time(0));
		return indexKeyMap[rand() % size];
	}

};

//int main()
//{
//	Pool pool;
//	pool.add("A");
//	pool.add("B");
//	pool.add("C");
//	pool.add("D");
//	pool.add("E");
//
//	cout << pool.getRandom() << endl;
//	cout << pool.getRandom() << endl;
//	pool.Delete("A");
//	cout << pool.getRandom() << endl;
//	cout << pool.getRandom() << endl;
//}