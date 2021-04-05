#include<iostream>
#include<vector>
using namespace std;

#if 0
class Solution {
public:
    vector<int> exchange(vector<int>& nums)
    {
        int length = nums.size();
        if (length == 0) return nums;
        int* p = &nums[0];        
        int* q = &nums[length - 1];

        while (p < q)
        {
            while (p < q && *p % 2 == 1)
            {
                p++;
            }
            while (p < q && *q % 2 == 0)
            {
                q--;
            }
            if (p < q)
            {
                swap(*p, *q);
            }
        }
        return nums;
    }
};

int main()
{
    Solution a;
    vector<int> num = { 1,1,6,1};

    for (int i = 0; i < 4; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;

    a.exchange(num);

    for (int i = 0; i < 4; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
#endif