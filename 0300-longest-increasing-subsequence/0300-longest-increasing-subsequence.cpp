class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=-1;j<i;j++){
                int take = 0;
                if(j==-1 || nums[i]>nums[j]){
                    take = 1+dp[i+1][i+1];
                }
                int nottake = dp[i+1][j+1];
                dp[i][j+1] = max(take,nottake);
                }
            }
        return dp[0][0];
    }
};