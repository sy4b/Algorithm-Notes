/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        // x有多少位
        int count=0;
        int temp=x;
        while(temp>0){
            count++;
            temp/=10;
        }
        // 只需要操作一半的位数
        // 对于奇数个位数，需要删掉中间的
        bool isOdd=(count%2==1);
        count=count>>1;
        temp=0;
        while(count>0){
            temp=temp*10+x%10;
            x/=10;
            count--;
        }
        if(isOdd)   x/=10;
        return x==temp;
    }
};
// @lc code=end

