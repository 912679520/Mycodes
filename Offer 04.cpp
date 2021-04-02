#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() == true) return false;

        int rows = matrix.size(); //行
        int columns = matrix[0].size() - 1;//列

        if (rows >= 0 && columns >= 0)
        {
            int row = 0;
            while (rows > row && columns >= 0)
            {
                if (matrix[row][columns] == target)
                {
                    return true;
                }
                else if (matrix[row][columns] > target)
                {
                    columns--;
                }
                else
                {
                    ++row;
                }
            }

        }
        return false;
    }
};

int main()
{
        int n, num;
        int sum = 0;
        cin >> n;
        //二维数组的定义
        vector<vector<int>> array(n);//行；这里指定了长度，所以每个元素都默认初始化为0了
        for (int i = 0;i < n;i++)
        {
            array[i].resize(n);//列
        }
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                cin >> num;
                //array[i].push_back(num);不可以使用这种方式，只是在末尾添加元素
                array[i][j] = num;
            }
        }
        Solution ar;
        bool fb = ar.findNumberIn2DArray(array, 7);
        cout << fb << endl;
        return 0;
    }
