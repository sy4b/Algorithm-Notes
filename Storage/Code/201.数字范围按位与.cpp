/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        // 找到公共前缀
        while(left!=right){
            ++count;
            left=left>>1;
            right=right>>1;
        }
        // 找到结果
        for(int i=0;i<count;++i){
            left=left<<1;
        }
        return left;
    }
};
// @lc code=end

