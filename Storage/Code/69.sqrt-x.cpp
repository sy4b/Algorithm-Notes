/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // 找到最后一个平方小于等于x的值
        if(x<=1)    return x;
        int left=1, right=x/2;
        while(left<right){
            int mid=left+((right-left+1)>>1);
            if((long long)mid*mid==x){
                return mid;
            }else if((long long)mid*mid<x){
                left=mid;
            }else{
                right=mid-1;
            }
        }
        return right;
    }
};
// @lc code=end

