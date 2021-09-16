/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start

int dp[20][20];
int solve(int l,int r){
    if(l>=r) return 1;
    int res=0;
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    for(int i=l;i<=r;i++){
        auto left = solve(l,i-1);
        auto right = solve(i+1,r);
        res += (left*right);
    }
    dp[l][r]=res;
    return res;
}
class Solution {
public:
    int numTrees(int n) {
        memset(dp,-1,sizeof dp);
        return solve(1,n);
    }
};
// @lc code=end

