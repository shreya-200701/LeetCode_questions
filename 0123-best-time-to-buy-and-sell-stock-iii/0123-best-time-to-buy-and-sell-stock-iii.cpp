class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        // Base case: no days left
        for(int cap = 0; cap <= 2; cap++) {
            dp[n][0][cap] = 0;
            dp[n][1][cap] = 0;
        }

        for(int i = n - 1; i >= 0; i--) {

            for(int j = 0; j < 2; j++) {

                for(int k = 0; k <= 2; k++) {

                    int profit = 0;

                    // No transactions remaining
                    if(k == 0) {
                        dp[i][j][k] = 0;
                        continue;
                    }

                    if(j) {
                        // Buy
                        profit = max(
                            -prices[i] + dp[i + 1][0][k],
                            dp[i + 1][1][k]
                        );
                    }
                    else {
                        // Sell
                        profit = max(
                            prices[i] + dp[i + 1][1][k - 1],
                            dp[i + 1][0][k]
                        );
                    }

                    dp[i][j][k] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};