#include<iostream>
#include<unordered_map>
#include<ctime>
#include<cstdlib>

using namespace std;

/*
	思路：使用两个哈希表
	正反：A第一个进来，第一个表key A， value 0
	第二个表key 0， value A
	随机第二个中的key，返回value

	insert：两个表同时加
	delete：直接删会有洞，随机会变慢
	将最后一个放在要删除的位置，不让产生洞

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
		//要删除的第一个表key的数据
		int deleteIndex = keyIndexMap.find(key)->second;
		//得到第二个表的key
		int lastIndex = --size;
		//将第二个表最后一个值放在要删的位置
		string lastKey = indexKeyMap.find(lastIndex)->second;
		indexKeyMap[deleteIndex] = lastKey;
		indexKeyMap.erase(lastIndex);

		//第一个表最后一个值放在要删的位置
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