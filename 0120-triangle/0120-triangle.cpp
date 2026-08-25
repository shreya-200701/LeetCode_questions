class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                if(i==0 && j==0){
                    dp[0][0] = triangle[0][0];
                }
                else if(j == 0 && i>0) {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }

                // Last element of row
                else if(j == i) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }

                // Middle elements
                else {
                    dp[i][j] = triangle[i][j] +
                               min(dp[i-1][j-1], dp[i-1][j]);
                }

            }
        }
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }
};