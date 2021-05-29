/*
前缀树的加：
一个字符串从头节点开始，依次看有没有沿途
的路，如果有复用，没有底下建出来
*/
#include<iostream>
#include<string>

using namespace std;

struct Node
{
	int path;
	int end;
	int count;
	Node* nexts[26];
};

class Trie
{
private:
	Node* root;
public:
	Trie()
	{
		root = new Node();
	}
	void insert(string word)
	{
		if (word.empty()) return;

		Node* ptr = root;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			if (ptr->nexts[index] == nullptr)
			{
				ptr->nexts[index] = new Node();
			}
			ptr = ptr->nexts[index];
			(*ptr).path++;
		}
		(*ptr).end++;
		
	}

	int search(string word)
	{
		if (word.empty()) return 0;

		Node* ptr = root;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			ptr = ptr->nexts[index];
		}
		return (*ptr).end;
	}
	void delete_(string word)
	{
		if (search(word) != 0)
		{
			Node* ptr = root;
			int index = 0;
			for (int i = 0; i < word.size(); i++)
			{
				index = word[i] - 'a';
				if (--(*(ptr->nexts[index])).path == 0)
				{
					ptr->nexts[index] = nullptr;
					return;
				}
				ptr = ptr->nexts[index];
			}
			ptr->end--;
		}
	}

	int prefixNumber(string pre)
	{
		if (pre.empty()) return 0;

		Node* ptr = root;
		int index = 0;
		for (int i = 0; i < pre.size(); i++)
		{
			index = pre[i] - 'a';
			if (ptr->nexts[index] == nullptr)
				return 0;

			ptr = ptr->nexts[index];
			return ptr->path;
		}
	}
};

int main()
{
	Trie sol;
	sol.insert("hello ya");
	sol.insert("how are you");
	sol.insert("hello ya");
	sol.insert("hello ya");
	sol.insert("hello ya");
	sol.insert("how do you do");
	sol.insert("what's up");
	sol.insert("whoo");
	sol.insert("bye");
	cout << "repeated word num:" << sol.search("hello ya") << endl;
	cout << "repeated prefix num:" << sol.prefixNumber("wh") << endl;;
	sol.delete_("hello ya");
	cout << "repeated word num:" << sol.search("hello ya") << endl;
	system("pause");

	return 0;

}