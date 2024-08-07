class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> pref_sum;
        pref_sum.push_back(0);
        for (int i=0; i<nums.size(); i++) {
            pref_sum.push_back(nums[i]);
        }
        for (int i=1; i<pref_sum.size(); i++) {
            pref_sum[i]+=pref_sum[i-1];
        }
        vector<int> sum_remainder_k;
        for (int i=0; i<pref_sum.size(); i++) {
            if (pref_sum[i]>=0) {
                sum_remainder_k.push_back(pref_sum[i]%k);
            }
            else {
                int curr_sum=pref_sum[i];
                while (curr_sum<0) {
                    curr_sum+=k;
                }
                sum_remainder_k.push_back(curr_sum);
            }
        }
        unordered_map<int,int> rem_freq;
        for (int i=0; i<sum_remainder_k.size(); i++) {
            rem_freq[sum_remainder_k[i]]++;
        }
        int pairs=0;
        for (auto rem:rem_freq) {
            int freq=rem.second;
            pairs+=(freq*(freq-1))/2;
        }
        return pairs;
    }
};
