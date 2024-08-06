class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> non_zeros;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=0) {
                non_zeros.push_back(nums[i]);
            }
        }
        for (int i=0; i<non_zeros.size(); i++) {
            nums[i]=non_zeros[i];
        }
        int index=non_zeros.size();
        while (index<nums.size()) {
            nums[index++]=0;
        }
    }
};
