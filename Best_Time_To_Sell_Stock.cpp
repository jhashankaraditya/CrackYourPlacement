class Solution {
    int solvetab(vector<int> &prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        for (int index=prices.size()-1; index>=0; index--) {
            for (int bought=1; bought>=0; bought--) {
                int profit=0;
                if (bought) {
                    if (index+1<prices.size()) {
                        profit=max(prices[index],dp[index+1][1]);
                    }
                    else profit=prices[index];
                }
                else {
                    if (index+1<prices.size()) {
                        profit=max(dp[index+1][1]-prices[index],dp[index+1][0]);
                    }
                    else profit=0;
                }
                dp[index][bought]=profit;
            }
        }
        return dp[0][0];
    }
public:
    int maxProfit(vector<int>& prices) {
        return solvetab(prices);
    }
};
