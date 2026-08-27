class Solution {
public:

    bool subsetSum(vector<int>& nums, int index, int target,
                   vector<vector<int>>& dp) {

        if(target == 0)
            return true;

        if(index == 0)
            return nums[0] == target;

        if(dp[index][target] != -1)
            return dp[index][target];

        bool notTake = subsetSum(nums, index - 1, target, dp);

        bool take = false;

        if(nums[index] <= target) {
            take = subsetSum(nums, index - 1,
                             target - nums[index], dp);
        }

        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums)
            sum += x;

        // Odd total cannot be divided equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return subsetSum(nums, n - 1, target, dp);
    }
};