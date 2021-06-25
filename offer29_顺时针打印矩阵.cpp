#include<iostream>
#include<vector>

using namespace std;

/*
    思想：宏观上看，记录一个左上角和右下角的下标
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};

        int Clen = matrix.size() - 1;
        int Rlen = matrix[0].size() - 1;

        int starti = 0, startj = 0;
        int endi = Clen, endj = Rlen;

        vector<int> res;

        while (starti <= endi && startj <= endj)
        {
            for (int j = startj; j <= endj; j++)
            {
                res.push_back(matrix[starti][j]);
            }
            for (int i = starti + 1; i <= endi;i++)
            {
                res.push_back(matrix[i][endj]);
            }
            if (starti < endi && startj < endj)
            {
                for (int j = endj - 1; j > startj; j--)
                {
                    res.push_back(matrix[endi][j]);
                }
                for (int i = endi; i > starti; i--)
                {
                    res.push_back(matrix[i][starti]);
                }
            }
            starti++;
            startj++;
            endi--;
            endj--;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {};

    Solution s;
    s.spiralOrder(matrix);

    return 0;
}