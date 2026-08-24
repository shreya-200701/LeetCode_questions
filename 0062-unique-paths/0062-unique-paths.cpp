class Solution {
public:
    int count(int m,int n,int x,int y,vector<vector<int>>&dp){
        if(x>=m){
            return 0;
        }
        if(y>=n){
            return 0;
        }
        if(x==m-1 && y==n-1 ){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        return dp[x][y] = count(m,n,x+1,y,dp) + count(m,n,x,y+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(m,n,0,0,dp);
    }
};