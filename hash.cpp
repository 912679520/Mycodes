#include "hash.h"
#include<string.h>
#include<stdlib.h>

void InitHash(MyHash* hash)
{
	if (hash == NULL) exit(0);

	for (int i = 0;i < HASHNUM;i++)
		hash->HashTable[i] = NULL;
}

//¹þÏ£º¯Êý
static int Hash(KeyType key)
{
	return key % HASHNUM;
}

static int SearchNot(MyHash* hash, KeyType key, int pos)
{
	HashNode* p = hash->HashTable[pos];

	while (p != NULL)
	{
		if (p->key == key) return 0;

		p = p->next;
	}

	return 1;
}

static HashNode* _ApplyHashNode(KeyType key, HashNode* next)
{
	HashNode* s = (HashNode*)malloc(sizeof(HashNode));
	if (s == NULL) return NULL;
	s->key = key;
	s->next = next;

	return s;
}

int InsertHash(MyHash* hash, KeyType key, KeyType val)
{
	if (hash == NULL) exit(0);

	int pos = Hash(key);

	if (SearchNot(hash, key, pos))
	{
		HashNode *s = _ApplyHashNode(key, hash->HashTable[pos]);
		if (s != NULL)
		{
			hash->HashTable[pos] = s;
			return 1;
		}
	}

	return 0;
}

HashNode* Search(MyHash* hash, KeyType key)
{
	if (hash == NULL) exit(0);

	HashNode* p = hash->HashTable[Hash(key)];

	while (p != NULL)
	{
		if (p->key == key) return p;

		p = p->next;
	}

	return NULL;
}

int DeleteHash(MyHash* hash, KeyType key)
{
	if (hash == NULL) exit(0);

	int pos = Hash(key);

	HashNode* p = hash->HashTable[pos];
	HashNode* pr = NULL;

	while (p != NULL)
	{
		if (p->key == key)
		{
			break;
		}

		pr = p;
		p = p->next;
	}

	if (p == NULL)
	{
		return 0;
	}

	if (pr == NULL)
	{
		hash->HashTable[pos] = p->next;
		free(p);
	}
	else
	{
		pr->next = p->next;
		free(p);
	}

	return 1;
}

void DestroyHash(MyHash* hash)
{
	if (hash == NULL) exit(0);

	for (int i = 0;i < HASHNUM;i++)
	{
		while (hash->HashTable[i] != NULL)
		{
			HashNode* p = hash->HashTable[i];
			hash->HashTable[i] = p->next;
			free(p);
		}
	}
}
