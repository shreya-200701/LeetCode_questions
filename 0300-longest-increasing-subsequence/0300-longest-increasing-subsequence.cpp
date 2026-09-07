class Solution {
public:
    int longest(vector<int>&nums,vector<vector<int>>&dp,int idx,int prev){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take = 0;
        if( prev==-1 || nums[idx]>nums[prev]){
            
            take = 1+longest(nums,dp,idx+1,idx);
        }
        int nottake = longest(nums,dp,idx+1,prev);
        return dp[idx][prev+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return longest(nums,dp,0,-1);
    }
};