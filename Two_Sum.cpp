class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,vector<int>> nums_pos;
        for (int i=0; i<nums.size(); i++) {
            nums_pos[nums[i]].push_back(i);
        }
        for (auto num:nums_pos) {
            int req_target=target-num.first;
            if (req_target!=num.first) {
                if (nums_pos.find(req_target)==nums_pos.end()) {
                    continue;
                }
                else ans={num.second[0],nums_pos[req_target][0]};
            }
            else {
                if (num.second.size()>1) {
                    ans={num.second[0],num.second[1]};
                }
                else continue;
            }
        }
        return ans;
    }
};
