class Solution {
public:

    bool check(string &small, string &large) {

        int i = 0;
        int j = 0;

        while(i < small.length() && j < large.length()) {

            if(small[i] == large[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i == small.length();
    }

    int longestStrChain(vector<string>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        sort(nums.begin(), nums.end(), [](string a, string b) {
            return a.length() < b.length();
        });

        for(int i = n - 1; i >= 0; i--) {

            for(int j = -1; j < i; j++) {

                int take = 0;

                if(j == -1 ||
                   (nums[i].length() == nums[j].length() + 1 &&
                    check(nums[j], nums[i]))) {

                    take = 1 + dp[i + 1][i + 1];
                }

                int nottake = dp[i + 1][j + 1];

                dp[i][j + 1] = max(take, nottake);
            }
        }

        return dp[0][0];
    }
};