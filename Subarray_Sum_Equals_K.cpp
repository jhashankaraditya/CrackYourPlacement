class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int subarrays=0;
        vector<int> pref_sum;
        pref_sum.push_back(0);
        pref_sum.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            pref_sum.push_back(nums[i]+pref_sum[i-1]);
        }
        unordered_map<int,vector<int>> pref_sum_pos;
        for (int i=0; i<pref_sum.size(); i++) {
            pref_sum_pos[pref_sum[i]].push_back(i);
        }
        for (int i=0; i<pref_sum.size(); i++) {
            int target=pref_sum[i]+k;
            int idx=lower_bound(pref_sum_pos[target].begin(),pref_sum_pos[target].end(),i)-pref_sum_pos[target].begin();
            cout<<i<<" "<<idx<<" "<<pref_sum_pos[target].size()<<"\n";
            subarrays+=(pref_sum_pos[target].size()-idx);
        }
        return subarrays;
    }
};
