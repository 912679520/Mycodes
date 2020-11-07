#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//朴素(简单)查找算法
int BF(const char *str,const char *sub,int pos)//O(n*m)
{
	int i = pos;
	int j = 0;
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	while(i<lenstr && j<lensub)
	{
		if(str[i] == sub[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i-j+1;//i回退到刚才的位置的下一个
			j = 0;
		}
	}
	if(j >= lensub)//子串完成,则找到
	{
		return i-j;
	}
	else
	{
		return -1;
	}
}

static int *GetNext(const char *sub)
{
	int len = strlen(sub);
	int *next = (int *)malloc(len*sizeof(int));
	next[0] = -1;
	next[1] = 0;

	int j = 1;
	int k = 0;
	while(j+1<len)
	{
		if(k==0 || sub[k]==sub[j])//next[j+1] = k+1
		{
			next[++j] = ++k;
		}
		else
		{
			k = next[k];//*****
		}
	}
	return next;
}

static int *GetNextVal(const char *sub)
{
	int len = strlen(sub);
	int *next = (int *)malloc(len*sizeof(int));
	int *nextval = (int *)malloc(len*sizeof(int));
	next[0] = -1;
	next[1] = 0;

	int j = 1;
	int k = 0;
	while(j+1<len)
	{
		if(k==0 || sub[k]==sub[j])//next[j+1] = k+1
		{
			next[++j] = ++k;
		}
		else
		{
			k = next[k];//*****
		}
	}
	//获取修正的next值,去掉无效的回退
	nextval[0] = -1;
	for(int i=1;i<len;i++)
	{
		if(sub[i] == sub[next[i]])
		{
			nextval[i] = nextval[next[i]];
		}
		else
		{
			nextval[i] = next[i];
		}
	}
	free(next);
	return nextval;
}

//KMP:1.O(n+m);2.i不回退
int KMP(const char*str,const char *sub,int pos)//O(n+m)
{
	int i = pos;
	int j = 0;
	int lenstr = strlen(str);
	int lensub = strlen(sub);
	int *next = GetNext(sub);
	int *next = GetNextVal(sub);
	while(i<lenstr && j<lensub)
	{
		if(j==-1 || str[i]==sub[j])
		{
			i++;
			j++;
		}
		else//失配
		{
			//KMP i不回退 //i = i-j+1;
			j = next[j];
		}
	}

	free(next);

	if(j >= lensub)
	{
		return i-j;
	}
	else
	{
		return -1;
	}
}

int main()
{
	char *str = "ababcabcdabcde";
	char *sub = "abcdf";
	printf("%d\n",KMP(str,sub,0));

	return 0;
}