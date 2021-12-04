/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */
/*
    滑动窗口
    0. 滑动条件：右边界在范围内
    1. 右边界右移：当前窗口内字符串满足连续字符（我们想继续扩大窗口，找到最大）
    2. 左边界左移：窗口内出现了其他字符（需要缩小窗口，以满足条件）
        本题可以直接移动到右边界处，而不是+1
    3. 窗口长度 right-left+1
*/
// @lc code=start
class Solution {
public:
    int maxPower(string s) {
        // 从index=1开始找
        int ans=1;          // 答案，初始化1
        char cur=s[0];      // 记录当前字符，初始化s[0]
        // 滑动窗口
        int left=0, right=1;
        while(right<s.size()){
            if(s[right]!=cur){
                ans=max(ans,right-left+1-1); // 此时right-1才是子串末尾
                left=right;
                cur=s[left];
            }
            ++right;
        }
        return max(ans,right-left+1-1);     // right出界的情况，再一次比较
    }
};
// @lc code=end

