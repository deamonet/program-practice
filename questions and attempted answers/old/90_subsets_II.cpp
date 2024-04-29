/*
90. 子集 II
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>
#include <map>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

void ShowVec(const vector<int> &valList)
{
    int count = valList.size();
    for (int i = 0; i < count; i++)
    {
        cout << valList[i] << "  ";
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


// 回溯算法：
/*
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
*/

class Solution
{
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> track;
        track.clear();
        ShowVec(nums);
        sort(nums.begin(), nums.end());
        backtrace(nums, 0, track);
        return res;
    }

    void backtrace(vector<int> &nums, int j, vector<int> track)
    {
        res.push_back(track);
        for (int i = j; i < nums.size(); i++)
        {
            if (i > j && nums[i] == nums[i - 1])
            {
                continue;
            }
            track.push_back(nums[i]);
            backtrace(nums, i + 1, track);
            track.pop_back();
        }
    }
};

int main()
{
    int arr[] = { 1, 2, 2 };
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution s;
    vector<vector<int>> res;
    res = s.subsetsWithDup(vec);
    Show2Vec(res);
}