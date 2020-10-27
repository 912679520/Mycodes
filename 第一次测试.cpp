

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

//输入
void insert(int n,int* nums)
{
	for(int i = 0; i< n; i++)
		scanf_s("%d",&nums[i]);
}

//1、一维数组前缀和
void rtSum(int n, int* nums)
{
	
	insert(n,nums);
	int* rtSum =(int*)malloc(sizeof(int)*n);
	rtSum[0] = nums [0];

	for(int i = 1; i < n; i++)
	{
		rtSum[i] = rtSum[i-1] + nums[i];
	}

	for (int i = 0; i < n; i++)
		printf("%d ",rtSum[i]);
	printf("\n");
}


//2、好数对的数量
int HSD(int n, int* nums)
{
	insert(n,nums);

	int count = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if (nums[i] == nums[j])
				count++;
		}
	}
	return count;
}

//3、重新排列数组
void NewSort(int n, int* nums,int* Nnums)
{
	insert(n,nums);
	
	int i = 0;
	for(int j = 0; j < n*2; j =j + 2)
	{
		Nnums[j] = nums[i];
		Nnums[j+1] =nums[i+n];
		i++;
	}
}

//4、数列异或操作
int Exor(int n,int start,int sum)
{
	int* num =(int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
	{
		num[i] = start + (2 * i);
	}

    sum = num[0];
	for(int j = 1; j < n; j++)
	{	
		sum = sum^num[j];
	}

	return sum;
}

//5、猜数字
int GuessNum(int *guess, int* answer)
{
	int count = 0;
	for(int i = 0; i < 3; i++)
	{
		if(guess[i] == answer[i])
			count++;
	}
	return count;
}

//6、宝石与石头（字符串）
int Str(char* J,char* S)
{
	int Jlen = strlen(J);
	int Slen = strlen(S);
	int count = 0;

	for(int i = 0; i < Jlen; i++)
	{
		for(int j = 0; j < Slen; j++)
		{
			if(J[i] == S[j])
				count++;
		}
	}
	return count;
}

//7、拿硬币（数组）
int Arr(int n, int *arr)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			count += arr[i] / 2;
		}
		else
		{
			if(arr[i] > 1)
			{
				count += (arr[i] / 2) + 1;
			}
			else
				count++;
		}
	}
	return count;
}

//8、将数字变成0的操作次数
int GetZeor(int num)
{
	int count = 0;
	while(num != 0)
	{
		if(num % 2 == 0)
		{
			num = num / 2;
			count++;
		}
		else
		{
			num = num - 1;
			count++;
		}
	}
	return count;
}

//9、数组中重复的数字
int Nums(int n, int* nums)
{
	int *p = &nums[0];
	int *q = &nums[1];
	while(*p != NULL)
	{
		if(*p == *q)
		{
			return *p;
			q++;
		}
		p++;
	}
}

//10、二进制中1的个数
int BinOne(unsigned int n)//-1未解决
{
	int count = 0;
	while(n != 0)
	{
		n &= n - 1;
		count++;
	}
	return count;
}

int main()
{
	
	printf("%d\n",BinOne(7));
	return 0;
}
