class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(k+1, -1))
        );

        // Base case: no days left
        for(int cap = 0; cap <= k; cap++) {
            dp[n][0][cap] = 0;
            dp[n][1][cap] = 0;
        }

        for(int i = n - 1; i >= 0; i--) {

            for(int j = 0; j < 2; j++) {

                for(int m = 0; m <= k; m++) {

                    int profit = 0;

                    // No transactions remaining
                    if(m == 0) {
                        dp[i][j][m] = 0;
                        continue;
                    }

                    if(j) {
                        // Buy
                        profit = max(
                            -prices[i] + dp[i + 1][0][m],
                            dp[i + 1][1][m]
                        );
                    }
                    else {
                        // Sell
                        profit = max(
                            prices[i] + dp[i + 1][1][m - 1],
                            dp[i + 1][0][m]
                        );
                    }

                    dp[i][j][m] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};