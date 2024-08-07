class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int nums1_idx=0, nums2_idx=0;
        while (nums1_idx<m && nums2_idx<n) {
            if (nums1[nums1_idx]<=nums2[nums2_idx]) {
                ans.push_back(nums1[nums1_idx++]);
            }
            else ans.push_back(nums2[nums2_idx++]);
        }
        while (nums1_idx<m) {
            ans.push_back(nums1[nums1_idx++]);
        }
        while (nums2_idx<n) {
            ans.push_back(nums2[nums2_idx++]);
        }
        for (int i=0; i<m+n; i++) {
            nums1[i]=ans[i];
        }
    }
};
