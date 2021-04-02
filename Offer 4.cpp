#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() == true) return false;

        int rows = matrix.size(); //��
        int columns = matrix[0].size() - 1;//��

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
        //��ά����Ķ���
        vector<vector<int>> array(n);//�У�����ָ���˳��ȣ�����ÿ��Ԫ�ض�Ĭ�ϳ�ʼ��Ϊ0��
        for (int i = 0;i < n;i++)
        {
            array[i].resize(n);//��
        }
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                cin >> num;
                //array[i].push_back(num);������ʹ�����ַ�ʽ��ֻ����ĩβ���Ԫ��
                array[i][j] = num;
            }
        }
        Solution ar;
        bool fb = ar.findNumberIn2DArray(array, 7);
        cout << fb << endl;
        return 0;
    }
