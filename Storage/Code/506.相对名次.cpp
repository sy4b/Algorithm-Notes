/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
/* 
    记录下标，进行排序
*/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int size=score.size();
        vector<pair<int, int>> vec(size);
        for(int i=0;i<size;++i){
            vec[i]=pair(score[i], i);
        }
        sort(vec.rbegin(), vec.rend());
        vector<string> ans(size);
        for(int i=0;i<size;++i){
            if(i==0){
                ans[vec[i].second]="Gold Medal";
            }else if(i==1){
                ans[vec[i].second]="Silver Medal";
            }else if(i==2){
                ans[vec[i].second]="Bronze Medal";
            }else{
                ans[vec[i].second]=to_string(i+1);
            }
        }
        return ans;
    }
};
// @lc code=end

