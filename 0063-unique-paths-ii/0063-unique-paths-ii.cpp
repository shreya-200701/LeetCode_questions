class Solution {
public:
    int count(vector<vector<int>>&obstacleGrid,int m,int n,int x,int y,vector<vector<int>>&dp){
        
        if(x>=m){
            return 0;
        }
        if(y>=n){
            return 0;
        }
        if(obstacleGrid[x][y]==1){
            return 0;
        }
        if(x==m-1 && y==n-1 ){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
        return dp[x][y] = count(obstacleGrid,m,n,x+1,y,dp) + count(obstacleGrid,m,n,x,y+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(obstacleGrid,m,n,0,0,dp);
    }
};