/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]=='0'){
            return;
        }
        grid[x][y]='0';
        vector<int> dx{0,0,-1,1}, dy{1,-1,0,0};
        for(int i=0;i<4;++i){
            dfs(grid, x+dx[i], y+dy[i]);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

