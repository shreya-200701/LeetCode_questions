class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int m = nums.size();
        vector<vector<int>>dp(m,vector<int>(m,0));

        for(int i=nums.size()-2;i>0;i--){
            for(int j=1;j<=nums.size()-2;j++ ){
                if(i>j){
                    continue;
                }
                int maxx = -1;
                for(int idx=i;idx<=j;idx++){
                    int steps = nums[i-1]*nums[idx]*nums[j+1] + dp[i][idx-1]+dp[idx+1][j];
                    maxx = max(maxx,steps);
                }
                dp[i][j] =  maxx;
            }
        }
        return dp[1][nums.size()-2];
    }
};