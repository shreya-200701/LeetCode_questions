class Solution {
public:
    int calculate(vector<int>& prices, vector<vector<int>>&dp,int idx, int buy,int profit){
        if(idx>=prices.size()){
            return 0l;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            profit = max(-prices[idx] + calculate(prices,dp,idx+1,0,profit), calculate(prices,dp,idx+1,1,profit));
        }else{
            profit = max(prices[idx] + calculate(prices,dp,idx+1,1,profit),calculate(prices,dp,idx+1,0,profit));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return calculate(prices,dp,0,1,0);
    }
};