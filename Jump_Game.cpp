class Solution {
    int solvetab(vector<int> &nums) {
        vector<int> dp(nums.size(),0);
        dp[nums.size()-1]=1;
        for (int index=nums.size()-2; index>=0; index--) {
            int jump_possible=0;
            int max_step=nums[index];
            for (int i=1; i<=max_step; i++) {
                jump_possible=jump_possible||dp[index+i];
            }
            dp[index]=jump_possible;
        }
        return dp[0];
    }
public:
    bool canJump(vector<int>& nums) {
        return solvetab(nums);
    }
};
