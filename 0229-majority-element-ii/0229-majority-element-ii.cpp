class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map <int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto each : mp){
            if(each.second>n/3){
               ans.push_back(each.first);
            }
        }
        return ans;
    }
};