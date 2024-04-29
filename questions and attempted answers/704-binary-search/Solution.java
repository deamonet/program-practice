/*
 * @lc app=leetcode.cn id=704 lang=java
 *
 * [704] 二分查找
 */

// @lc code=start

// 用双指针法很简单，循环破除条件就是指针越界。
// 但是用我这种思路，由于每一次除法的不同，不好定位到数组中间。

class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid;
        while (left <= right){
            mid = left + (right - left) / 2;
            if (nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
}
// @lc code=end