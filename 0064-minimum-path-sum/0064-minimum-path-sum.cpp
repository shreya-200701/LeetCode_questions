class Solution {
public:
    int pathsum(vector<vector<int>>& grid, vector<vector<int>>&dp,int i,int j,int n,int m){
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(i>=n || j>=m){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] =  grid[i][j] + min(pathsum(grid,dp,i+1,j,n,m),pathsum(grid,dp,i,j+1,n,m));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return pathsum(grid,dp,0,0,n,m);
    }
};