class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> nums_freq;
        for (int i=0; i<nums.size(); i++) {
            nums_freq[nums[i]]++;
        }
        int max_freq=0, majority_element=-1;
        for (auto num:nums_freq) {
            if (num.second>max_freq) {
                max_freq=num.second;
                majority_element=num.first;
            }
        }
        return majority_element;
    }
};
