class Solution {
public:
    int count(vector<int>&nums,int amount,vector<vector<int>>&dp,int index){
        if(index<0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        if(amount==0){
            return 1;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int notpick = count(nums,amount,dp,index-1);
        int pick = 0;
        if(amount>=nums[index]){
            int temp = count(nums,amount-nums[index],dp,index);
            if(temp!=-1 && temp!=0){
                pick = temp;
            }
        }
        return dp[index][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return count(coins,amount,dp,coins.size()-1);
    }
};