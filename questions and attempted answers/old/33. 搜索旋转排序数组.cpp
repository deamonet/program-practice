/*
33. 搜索旋转排序数组
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

/*
我的思路，用两遍折半查找。第一遍找出头尾相接点，第二遍，找出目标值
[4,5,6,7,0,1,2] 中间的间隔值 等价于 [0,0,0,1,0,0]

这个思路对了一半，并不能通过二分查找找出1，实际上就是一次遍历，遍历的复杂度是O(n)
事实上的确可以用二分查找找出间断点。因为整个数组是递增的，这会导致第一个数绝对大于最后一个数。
那么间断点左侧的值，大于间断点右侧的值。
所以对于中间值而言，存在两种情况，如果同时大于第一个数和最后一个数，那么说明中间值在间断点的右侧。
如果同时小于第一个数和最后一个数，那么说明中间值在间断点的左侧。
这样根据中间值即可，判断间断点的位置。
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


class Solution
{
public:
    int half_search_target(int i, int j, vector<int> &nums, int target)
    {
        if (i == j){return 0;}

        int middle = (j - i) / 2 + i;
        if (nums[middle] == target)
        {
            return middle;
        }
        else
        {
            int res1 = half_search_middle(i, middle);
            int res2 = half_search_middle(middle + 1, j);
        }
        return res1 + res2;
    }

    int half_search_middle(int i, int j, vector<int> &nums)
    {
        if(i==j){return 0;}
        
        int middle = (j - i) / 2 + i;
        if(nums[middle] > nums[middle+1])
        {
            return middle;
        }else
        {
            int res1 = half_search_middle(i, middle);
            int res2 = half_search_middle(middle+1, j);
        }
        return res1 + res2;
    }

    int search(vector<int> &nums, int target)
    {
        int curcuit = half_search_middle(0, nums.size());

    }
};



//别人家的优秀解法

/*

极简 Solution
人工制能
发布于 10 个月前
28.2k

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

/*
以二分搜索为基本思路

简要来说：

nums[0] <= nums[mid]（0 - mid不包含旋转）且nums[0] <= target <= nums[mid] 时 high 向前规约；

nums[mid] < nums[0]（0 - mid包含旋转），target <= nums[mid] < nums[0] 时向前规约（target 在旋转位置到 mid 之间）

nums[mid] < nums[0]，nums[mid] < nums[0] <= target 时向前规约（target 在 0 到旋转位置之间）

其他情况向后规约

也就是说nums[mid] < nums[0]，nums[0] > target，target > nums[mid] 三项均为真或者只有一项为真时向后规约。

原文的分析是：

注意到原数组为有限制的有序数组（除了在某个点会突然下降外均为升序数组）

if nums[0] <= nums[I] 那么 nums[0] 到 nums[i] 为有序数组,那么当 nums[0] <= target <= nums[i] 时我们应该在 0-i0−i 范围内查找；

if nums[i] < nums[0] 那么在 0-i0−i 区间的某个点处发生了下降（旋转），那么 I+1I+1 到最后一个数字的区间为有序数组，并且所有的数字都是小于 nums[0] 且大于 nums[i]，当target不属于 nums[0] 到 nums[i] 时（target <= nums[i] < nums[0] or nums[i] < nums[0] <= target），我们应该在 0-i0−i 区间内查找。
上述三种情况可以总结如下：

    nums[0] <= target <= nums[i]
               target <= nums[i] < nums[0]
                         nums[i] < nums[0] <= target
                         
所以我们进行三项判断：

(nums[0] <= target)， (target <= nums[i]) ，(nums[i] < nums[0])，现在我们想知道这三项中有哪两项为真（明显这三项不可能均为真或均为假（因为这三项可能已经包含了所有情况））

所以我们现在只需要区别出这三项中有两项为真还是只有一项为真。

使用 “异或” 操作可以轻松的得到上述结果（两项为真时异或结果为假，一项为真时异或结果为真，可以画真值表进行验证）

之后我们通过二分查找不断做小 target 可能位于的区间直到 low==high，此时如果 nums[low]==target 则找到了，如果不等则说明该数组里没有此项。
*/


/*
官方答案：

方法：二分查找
题目要找到一种 O(logN)O(logN) 时间内的搜索方法，这提示我们可以用二分查找的方法。

算法非常直接：

找到旋转的下标 rotation_index ，也就是数组中最小的元素。二分查找在这里可以派上用场。
在选中的数组区域中再次使用二分查找。

1 / 3

JavaPython
*/
class Solution {
  int [] nums;
  int target;

  public int find_rotate_index(int left, int right) {
    if (nums[left] < nums[right])
      return 0;

    while (left <= right) {
      int pivot = (left + right) / 2;
      if (nums[pivot] > nums[pivot + 1])
        return pivot + 1;
      else {
        if (nums[pivot] < nums[left])
          right = pivot - 1;
        else
          left = pivot + 1;
      }
    }
    return 0;
  }

  public int search(int left, int right) {
    /*
    Binary search
    */
while (left <= right)
{
    int pivot = (left + right) / 2;
    if (nums[pivot] == target)
        return pivot;
    else
    {
        if (target < nums[pivot])
            right = pivot - 1;
        else
            left = pivot + 1;
    }
}
return -1;
}

public
int search(int[] nums, int target)
{
    this.nums = nums;
    this.target = target;

    int n = nums.length;

    if (n == 0)
        return -1;
    if (n == 1)
        return this.nums[0] == target ? 0 : -1;

    int rotate_index = find_rotate_index(0, n - 1);

    // if target is the smallest element
    if (nums[rotate_index] == target)
        return rotate_index;
    // if array is not rotated, search in the entire array
    if (rotate_index == 0)
        return search(0, n - 1);
    if (target < nums[0])
        // search in the right side
        return search(rotate_index, n - 1);
    // search in the left side
    return search(0, rotate_index);
}
}

/*
复杂度分析

时间复杂度： O(logN) O(logN) 。 空间复杂度： O(1) O(1) 。

    作者：LeetCode
    链接：https : //leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode/
                  来源：力扣（LeetCode）
                  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/