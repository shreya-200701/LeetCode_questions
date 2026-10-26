class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int>m1;
        for(int i=0;i<nums.size();i++){
            m1[i+1]=0;
        }
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        for(auto each : m1){
            if(each.second==0){
                return each.first;
            }
        }
        return 0;
    }
};