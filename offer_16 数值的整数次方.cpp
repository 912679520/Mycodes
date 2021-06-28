ʵ��?pow(x,?n)?�������� x �� n ���ݺ���������xn��������ʹ�ÿ⺯����
ͬʱ����Ҫ���Ǵ������⡣

?

ʾ�� 1��

���룺x = 2.00000, n = 10
�����1024.00000
ʾ�� 2��

���룺x = 2.10000, n = 3
�����9.26100
ʾ�� 3��

���룺x = 2.00000, n = -2
�����0.25000
���ͣ�2-2 = 1/22 = 1/4 = 0.25

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

/*
	˼�룺���ַ�������������Ļ���result��¼�����������Ǹ� 
*/

class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0) return 1;

        if(n < 0) 
        {
            n = -n;
            x = 1 / x;
        }

        double result = 1;
        while(n)
        {
            if(n & 1) result *= x; 
            x *= x;
            n >>= 1; 
        }
        return result;
    }
};
