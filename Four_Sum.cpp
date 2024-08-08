#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        map<vector<int>,bool> quad_marked;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                for (int k=j+1; k<nums.size(); k++) {
                    ll int curr_target=target;
                    curr_target-=nums[i];
                    curr_target-=nums[j];
                    curr_target-=nums[k];
                    int idx=upper_bound(nums.begin()+k+1,nums.end(),curr_target)-nums.begin();
                    idx--;
                    if (idx>k && idx<nums.size()) {
                        if (nums[idx]==curr_target) {
                            vector<int> quad={nums[i],nums[j],nums[k],nums[idx]};
                            if (!quad_marked[quad]) {
                                quad_marked[quad]=1;
                                quadruplets.push_back(quad);
                            }
                        }
                    }
                }
            }
        }
        return quadruplets;
    }
};
