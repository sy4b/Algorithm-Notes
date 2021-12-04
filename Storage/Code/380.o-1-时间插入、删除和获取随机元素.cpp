/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
/* 
    关键在O（1）完成随机查找
    可以配合一个数组实现
*/
// @lc code=start
class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> ans;
public:
    RandomizedSet() {
        mp.clear();
        ans.clear();
    }
    
    bool insert(int val) {
        if(mp.count(val)!=0){
            return false;
        }
        mp[val]=ans.size();
        ans.push_back(val);
        return true;
    }
    // 将数组欲删除位置的元素换成最后一个元素，更改map，然后移除数组末尾
    bool remove(int val) {
        if(mp.count(val)==0)    return false;
        mp[ans.back()]=mp[val];
        ans[mp[val]]=ans.back();
        ans.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return ans[rand()%ans.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

