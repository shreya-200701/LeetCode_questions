class Solution {
public:
    int noofways(int n,int k,vector<int>& dp){
        if(k==0){
            return 1;
        }
        if(k<0){
            return 0;
        }
        if(dp[k]!=-1){
            return dp[k];
        }
        return dp[k] = noofways(n,k-1,dp) + noofways(n,k-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return noofways(n,n,dp);
    }
};