输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]

思想：用一次快排的过程partation过程，一次排序后，返回基准点的位置
基准点前面的都小于它，后面的都大于它。 要是k在基准点前面，
则前面的数都是比基准小的，递归调用，继续排从头到k位置的数。
要是k在基准点后面，则重新排基准点到k位置上的。直到基准点和k相等。
返回从头开始到基准点的数。

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
