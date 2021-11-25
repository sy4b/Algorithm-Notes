/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index=digits.size()-1;
        while(index>=0){
            if(digits[index]!=9){
                ++digits[index];
                for(int i=index+1;i<digits.size();++i){
                    digits[i]=0;
                }
                return digits;
            }
            --index;
        }
        vector<int> ans(digits.size()+1,0);
        ans[0]=1;
        return ans;
    }
};
// @lc code=end

