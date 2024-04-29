#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void ShowVec(const vector<int> &valList)
{
    int count = valList.size();
    for (int i = 0; i < count; i++)
    {
        cout << valList[i] << "\t";
    };
    cout << "\n";
}

void Show2Vec(const vector<vector<int>> &vallist2)
{
    int count = vallist2.size();
    for (int i = 0; i < count; i++)
    {
        cout << "\n";
        ShowVec(vallist2[i]);
    }
}

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector< vector<int> > res;
        vector<int> temp[2];
        res.clear();
        for(int j = 1; j<n - k; j++)
        {
            temp[0] = j;
            while( k > 1)
            {
                for (int m = j+1; m <= n; m++)
                {
                    temp[1] = m;
                }
                res.push_back(temp);
                k--;
            }
            
        }
        return res;
    }
};

int main()
{
    Solution s;
    Show2Vec(s.combine(4, 2));
}