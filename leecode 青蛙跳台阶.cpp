/*
	������̨�ס�����ָoffer
	һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ�� n?����̨���ܹ��ж�����������

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��

ʾ�� 1��

���룺n = 2
�����2
ʾ�� 2��

���룺n = 7
�����21
ʾ�� 3��

���룺n = 0
�����1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע�������� 

*/ 


int numWays(int n){

    if(n == 0 || n == 1)
        return 1;

    int Numone = 1;
    int Numtwo = 1;
    int num = 0;

    for(int i = 2; i <= n; i++)
    {
        num = (Numone + Numtwo) % 1000000007;
        Numtwo = Numone;
        Numone = num;        
    }
    return num;
}
