/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    res++;
                    eraseIsland(grid,i,j,n,m);
                }
            }
        }
        return res;
    }
    void eraseIsland(vector<vector<char>> &grid,int i,int j,int n,int m){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]=='0') return ;
        grid[i][j]='0';
        eraseIsland(grid,i-1,j,n,m);
        eraseIsland(grid,i,j-1,n,m);
        eraseIsland(grid,i+1,j,n,m);
        eraseIsland(grid,i,j+1,n,m);
    }
};
// @lc code=end

