/*
 * @lc app=leetcode.cn id=27 lang=java
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
    public static int removeElement(int[] nums, int val) {
        if (nums.length == 0){
            return 0;
        } else {
            int cnt = 0;
            for (int i=0, j=nums.length-1; i<=j; i++, j--){
                if (nums[i]==val && nums[j]==val){
                    i--;
                    cnt++;
                } else if (nums[i]!=val && nums[j]!=val){
                    j++;
                } else if (nums[i]==val && nums[j]!=val){
                    nums[i] = nums[j];
                    cnt++;
                } else{
                    cnt++;
                    continue;
                }
            }
            return nums.length - cnt;
        }
    }
}
// @lc code=end

