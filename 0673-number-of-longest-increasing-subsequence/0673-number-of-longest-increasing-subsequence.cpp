class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>count(nums.size(),1);
        int length = 0;
        int result = 0;
        for(int i=nums.size()-1;i>=0;i--){
            int maxlength =1;
            int maxcount =1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    if(dp[j]+1>maxlength){
                        maxlength = dp[j]+1;
                        maxcount = count[j];
                    }
                    else if(dp[j]+1==maxlength){
                        maxcount = maxcount +  count[j];
                    }
                }
            }
            if(maxlength>length){
                        length = maxlength;
                        result = maxcount;
                    }else if(maxlength == length){
                        result = result + maxcount;
                    }
            dp[i] = maxlength;
            count[i] = maxcount;
        }
        return result;
    }
};