������������ arr ���ҳ�������С�� k ���������磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��

 

ʾ�� 1��

���룺arr = [3,2,1], k = 2
�����[1,2] ���� [2,1]
ʾ�� 2��

���룺arr = [0,1,2,1], k = 1
�����[0]

˼�룺��һ�ο��ŵĹ���partation���̣�һ������󣬷��ػ�׼���λ��
��׼��ǰ��Ķ�С����������Ķ��������� Ҫ��k�ڻ�׼��ǰ�棬
��ǰ��������ǱȻ�׼С�ģ��ݹ���ã������Ŵ�ͷ��kλ�õ�����
Ҫ��k�ڻ�׼����棬�������Ż�׼�㵽kλ���ϵġ�ֱ����׼���k��ȡ�
���ش�ͷ��ʼ����׼�������

 class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0 || arr.size() == 0) return vector<int>();

        return quickSearch(arr, 0, arr.size() - 1, k - 1);
    }

    vector<int> quickSearch(vector<int>& arr, int left, int right, int k)
    {
        int j = partition(arr, left, right);
        
        vector<int> res;
        if (j == k)
        {
            res.assign(arr.begin(), arr.begin() + j + 1);
            return res;
        }
        return j > k ? quickSearch(arr, left, j - 1, k)
            : quickSearch(arr, j + 1, right, k);
    }
    int partition(vector<int>& arr, int left, int right)
    {
        int less = left - 1;
        int more = right;

        while (left < more)
        {
            if (arr[left] < arr[right])
            {
                swap(arr[++less], arr[left++]);
            }
            else if (arr[left] > arr[right])
            {
                swap(arr[left], arr[--more]);
            }
            else
            {
                left++;
            }
        }
        swap(arr[more], arr[right]);

        return more;
    }
};
