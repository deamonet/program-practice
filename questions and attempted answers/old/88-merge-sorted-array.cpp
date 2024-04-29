/*
88. 合并两个有序数组
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。

 

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/

#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>

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

//这个解法是错的
class Solution2
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = k; j < m; j++)
            {
                if (nums1[j] >= nums2[i])
                {
                    nums1.insert(nums1.begin() + j, nums2[i]);
                    k = j + 1;
                    break;
                }
            }
        }
    }
};


//别人的解法：从后向前遍历。
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int last = m + n - 1;
        while (n)
        {
            if (m == 0 || nums1[m - 1] <= nums2[n - 1])
            {
                nums1[last--] = nums2[--n];
            }
            else
            {
                nums1[last--] = nums1[--m];
            }
        }
    }
};


int main(){
    static const int arr[] = { 1, 2, 3, 0, 0, 0 };
    static const int arr2[] = { 2, 5, 6 };
    int m=3, n=3;
    vector<int> nums1(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    Solution s;
    s.merge(nums1, m, nums2, n);
    ShowVec(nums1);
}
