/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // sum + m(n-1)= p*n
        // p = minNum + m
        // sum + m(n-1) = (minNum+m)*n
        // sum + m(n-1) -mn = minNum*n
        // sum -m = minNum*n
        // m = minNum*n-sum
        int minNum = *min_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        return  sum - minNum*nums.size();
    }
};
// @lc code=end

