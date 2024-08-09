class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> repeated;
        for (int i=0; i<nums.size(); i++) {
            int idx=abs(nums[i])-1;
            if (nums[idx]<0) {
                repeated.push_back(abs(nums[i]));
            }
            else nums[idx]*=(-1);
        }
        return repeated;
    }
};
