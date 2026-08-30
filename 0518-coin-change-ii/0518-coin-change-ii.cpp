class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));

        for(int i=0;i<coins.size();i++){
            dp[i][0] = 1;
        }
        for(int j = coins[0]; j <= amount; j++) {
            dp[0][j] = dp[0][j - coins[0]];
        }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<amount+1;j++){

                long long notpick = dp[i-1][j];
                long long  pick = 0;
                if(j>=coins[i]){
                    pick = dp[i][j-coins[i]];
                }

                dp[i][j] = pick+notpick;
            }
        }
        if(dp[coins.size()-1][amount]==-1){
            return 0;
        }
        return dp[coins.size()-1][amount];
    }
};