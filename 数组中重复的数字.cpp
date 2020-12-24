/*
	�ҳ��������ظ������֡�


��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
���ҳ�����������һ���ظ������֡�

���룺
[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3 

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


int findRepeatNumber(int* nums, int numsSize){

    if(nums == NULL || numsSize <= 1 || numsSize >= 100000) return -1;

    /*
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] < 0 || nums[i] > numsSize -1)
            return -1;
    }
    */
    for(int i = 0; i < numsSize; i++)
    {
        while(nums[i] != i)
        {
            if(nums[i] == nums[nums[i]])
                return nums[i];
            else
            {
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
           
        }
    }
    return -1;
}
