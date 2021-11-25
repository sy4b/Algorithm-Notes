/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1, right=n;
        while (left<right){
            int mid=left+((right-left)>>1);
            if(isBadVersion(mid)==false){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return left;
    }
};
// @lc code=end

