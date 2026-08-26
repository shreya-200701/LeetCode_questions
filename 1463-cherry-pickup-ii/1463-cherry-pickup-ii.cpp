class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1))
        );

        // Initial positions
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

        for(int i = 1; i < n; i++) {

            for(int j1 = 0; j1 < m; j1++) {

                for(int j2 = 0; j2 < m; j2++) {

                    int cherries = grid[i][j1];

                    if(j1 != j2)
                        cherries += grid[i][j2];

                    // Both robots can move -1, 0, +1
                    for(int d1 = -1; d1 <= 1; d1++) {

                        for(int d2 = -1; d2 <= 1; d2++) {

                            int prev1 = j1 - d1;
                            int prev2 = j2 - d2;

                            if(prev1 >= 0 && prev1 < m &&
                               prev2 >= 0 && prev2 < m) {

                                if(dp[i-1][prev1][prev2] != -1) {
                                    dp[i][j1][j2] = max(
                                        dp[i][j1][j2],
                                        dp[i-1][prev1][prev2] + cherries
                                    );
                                }
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                ans = max(ans, dp[n-1][j1][j2]);
            }
        }

        return ans;
    }
};