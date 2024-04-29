/*
 * @lc app=leetcode.cn id=204 lang=java
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
    public int countPrimes(int n) {
        int cnt = 0;
        int[] axis = new int[n+1];
        // 这里数轴加一个，是为了避免后续代码index out of bound错误
        Arrays.fill(axis, 1);
        for(int i=2; i<n; i++){
            if (axis[i] == 1){
                cnt++;
                for (int j=i; j<=n/i; j++){
        // java的整数除法，得到的结果省去小数部分，所以要加上等于。
        // 同时考虑到整除的情况，i*j最大是n，给axis增长一个避免报错。
        // leetcode上的代码同时用了if判断和for循环语句当中的判断。
        // 觉得有些多余所以采用了这种写法。
                    axis[i*j] = 0;
                }
            }
        }
        return cnt;
    }
}
// @lc code=end

