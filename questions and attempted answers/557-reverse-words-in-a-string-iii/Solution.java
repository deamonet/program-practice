import java.util.Objects;

import javax.sound.sampled.ReverbType;

/*
 * @lc app=leetcode.cn id=557 lang=java
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (74.15%)
 * Likes:    426
 * Dislikes: 0
 * Total Accepted:    225.4K
 * Total Submissions: 304K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入： s = "God Ding"
 * 输出："doG gniD"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * s 包含可打印的 ASCII 字符。
 * s 不包含任何开头或结尾空格。
 * s 里 至少 有一个词。
 * s 中的所有单词都用一个空格隔开。
 * 
 * 
 */

// @lc code=start
class Solution {
    public static void main(String[] args){
        String s = "first";
        String ret = reverseWords(s);
        System.out.println(ret);
    }

    public static String reverseWords(String s) {
        int left, right;
        char space = ' ';
        StringBuilder temp;
        StringBuilder ret = new StringBuilder();
        left = 0;
        for (right=0; right < s.length(); right++){
            if (Objects.equals(s.charAt(right), space)){
                temp = new StringBuilder(s.substring(left, right));
                ret.append(temp.reverse().toString());
                ret.append(space);
                left = right + 1;
            }
        }
        temp = new StringBuilder(s.substring(left));
        ret.append(temp.reverse().toString());
        return ret.toString();
    }
}
// @lc code=end