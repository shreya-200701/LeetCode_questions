class Solution {
public:
    int count(unordered_map<int,unordered_map<int,int>> &mp,vector<int>&nums,int target,int index){
        if(index<0){
            return (target==0);
        }
        if(mp[index].find(target)!=mp[index].end()){
            return mp[index][target];
        }
        int negative = count(mp,nums,target+nums[index],index-1);
        int positive = count(mp,nums,target-nums[index],index-1);

        return mp[index][target] = negative + positive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int,int>>mp;
        return count(mp,nums,target,nums.size()-1);
    }
};