class Solution {
public:
    int maxmoney(vector<int>& nums, vector<int>& dp, int curr){
        if(curr==0){
            return nums[0];
        }
        if(curr<0){
            return 0;
        }
        if(dp[curr]!=-1){
            return dp[curr];
        }
        return dp[curr] = max(nums[curr] + maxmoney(nums,dp,curr-2) , maxmoney(nums,dp,curr-1));
    }
    int rob(vector<int>& nums) {
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(maxmoney(temp1,dp1,temp1.size()-1) , maxmoney(temp2,dp2,temp2.size()-1));
    }
};