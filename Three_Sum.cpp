class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            for (int j=i+1; j<n; j++) {
                if (j>0 && j-i>1 && nums[j]==nums[j-1]) {
                    continue;
                }
                int target=(nums[i]+nums[j])*(-1);
                int target_idx=lower_bound(nums.begin()+j+1,nums.end(),target)-nums.begin();
                if (target_idx>j && target_idx<nums.size() && nums[target_idx]==target) {
                    vector<int> triplet={nums[i],nums[j],nums[target_idx]};
                    triplets.push_back(triplet);
                }
            }
        }
        return triplets;
    }
};
