class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> nums_freq;
        for (int i=0; i<nums.size(); i++) {
            nums_freq[nums[i]]++;
        }
        vector<int> dist_elements;
        for (auto num:nums_freq) {
            dist_elements.push_back(num.first);
        }
        sort(dist_elements.begin(),dist_elements.end());
        int k=dist_elements.size();
        for (int i=0; i<k; i++) {
            nums[i]=dist_elements[i];
        }
        int index=k;
        for (auto num:nums_freq) {
            int freq=num.second-1;
            while (freq--) {
                nums[index++]=num.first;
            }
        }
        return k;
    }
};
