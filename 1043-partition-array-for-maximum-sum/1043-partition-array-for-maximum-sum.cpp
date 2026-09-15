class Solution {
public:
    int f(vector<int>&arr,int i,int k,vector<int>&dp){
        int n=arr.size();
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int length=0;
        int maxi = INT_MIN;
        int maxans = 0;
        for(int j=i;j<min(n,i+k);j++){
            length++;
            maxi = max(maxi,arr[j]);
            int sum = length*maxi + f(arr,j+1,k,dp);
            maxans = max(maxans,sum);
        }
        return dp[i] = maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return f(arr,0,k,dp);
    }
};