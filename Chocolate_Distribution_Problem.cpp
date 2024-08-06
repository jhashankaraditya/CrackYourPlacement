class Solution{
  public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        long long left=0, right=m-1, min_diff=1e9;
        while (right<n) {
            if (min_diff>a[right]-a[left]) {
                min_diff=a[right]-a[left];
            }
            left++;
            right++;
        }
        return min_diff;
    }
}
