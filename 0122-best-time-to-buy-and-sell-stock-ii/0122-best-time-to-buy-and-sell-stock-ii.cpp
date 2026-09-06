class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        dp[prices.size()][0]=0;
        dp[prices.size()][1]=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int profit = 0;
                if(dp[i][j]!=-1){
                    return dp[i][j];
                }
                if(dp[i][j]!=-1){
                    return dp[i][j];
                }
                if(j){
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }else{
                    profit = max(prices[i] + dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
};