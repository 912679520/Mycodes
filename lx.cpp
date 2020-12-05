#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int ** p;
	int ** q;
	int * w;
	int * best;
	int n;
	int bestsum;
}Sport;

void Swap(int &a,int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void Compute(Sport &S)
{
	int sum = 0;
	for(int i = 0; i < S.n; i++)
	{
		S.best[i] = S.w[i];
	}
}

void Backtrack(int t, Sport &S)
{
	if(t >= S.n)
		Compute(S);
	else
		for(int i = t; i < S.n; i++)
		{
			Swap(S.w[t], S.w[i]);
			Backtrack(t+1, S);
			Swap(S.w[t], S.w[i]);
		}
}

void Destroy(Sport &S)
{
	int i;
	for(i = 0; i < S.n; i++)
	{
		free(S.p[i]);
		free(S.q[i]);
	}
	free(S.p);
	free(S.q);
	free(S.best);
	free(S.w);
	S.q = S.p = NULL;
	S.best = S.w = NULL;
}

void SetSport(Sport &S)
{
	int i, j;
	printf("input :");
	scanf("%d",&S.n);
	S.p = (int **) malloc (S.n * sizeof(int));
	S.q = (int **) malloc (S.n * sizeof(int));
	S.w = (int *) malloc (S.n * sizeof(int));
	S.best = (int *) malloc (S.n * sizeof(int));
	if(S.p == NULL || S.q == NULL || S.w == NULL || S.best == NULL)
	{
		printf("error!!\n");
		exit(-1);
	}
	for(i = 0; i < S.n; i++)
	{
		S.w[i] = i;
		S.p[i] =(int *) malloc (S.n * sizeof(int));
		S.q[i] = (int *)malloc (S.n * sizeof(int));
		if(S.p[i] == NULL || S.q[i] == NULL)
		{
			printf("error!!\n");
			exit(-1);
		}
	}
	printf("请输入男或女运动员的竞赛优势：\n");
	for(i=0; i<S.n; i++)
	{
		for(j=0; j<S.n; j++)
		{
			scanf("%d",&S.q[i][j]);
		}

	}
}

void Output(Sport &S)
{
	int i;
	for(i=0; i<S.n; i++)
	{
		printf("第%号男运动员配第%号女运动员\n",i,S.best[i]);
	}
	printf("最大配对总和为：%d\n",S.bestsum);
}

int main()
{
	Sport S;

	SetSport(S);
	Backtrack(0,S);
	Output(S);
	Destroy(S);

	return 0;
}


