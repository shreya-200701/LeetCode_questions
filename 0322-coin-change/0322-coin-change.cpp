class Solution {
public:
    int count(vector<int>& coins , int amount, vector<vector<int>>&dp,int index){
        if(amount==0){
            return 0;
        }
        if(index<0){
            return INT_MAX;
        }
        if(dp[index][amount] !=-1){
            return dp[index][amount];
        }
        int notpick = count(coins,amount,dp,index-1);
        int pick = INT_MAX;
        if(amount>=coins[index]){
            int temp = count(coins,amount-coins[index],dp,index);
            if(temp!=INT_MAX){
                pick = 1+ temp;
            }
        }
        return dp[index][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = count(coins,amount,dp,coins.size()-1);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};