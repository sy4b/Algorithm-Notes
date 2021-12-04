/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */
/*
    从左到右依次入栈
    碰撞的情况：
    前小行星向左，栈顶小行星向右，需要检测是否连续碰撞
*/
// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto& a: asteroids){
            while(!ans.empty() && ans.back()>0 && ans.back()<-a){
                ans.pop_back();
            }
            if(!ans.empty() && a<0 && ans.back()==-a){
                ans.pop_back();
            }else if(ans.empty() || a>0 || ans.back()<0){
                ans.push_back(a);
            }
        }
        return ans;
    }
};
// @lc code=end

