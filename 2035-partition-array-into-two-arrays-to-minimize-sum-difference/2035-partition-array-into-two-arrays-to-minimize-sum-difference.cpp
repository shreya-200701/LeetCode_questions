class Solution {
public:

    void generate(vector<int>& nums, int index, int end,
                  int count, int sum,
                  vector<vector<int>>& dp) {

        if(index == end) {
            dp[count].push_back(sum);
            return;
        }

        // Don't take
        generate(nums, index + 1, end,
                 count, sum, dp);

        // Take
        generate(nums, index + 1, end,
                 count + 1, sum + nums[index], dp);
    }

    int minimumDifference(vector<int>& nums) {

        int N = nums.size();
        int n = N / 2;

        int totalsum = 0;

        for(int x : nums) {
            totalsum += x;
        }

        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);

        // Generate subset sums of both halves
        generate(nums, 0, n, 0, 0, left);
        generate(nums, n, N, 0, 0, right);

        // Sort right subset sums
        for(int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int mini = INT_MAX;

        // Choose i elements from left
        for(int i = 0; i <= n; i++) {

            // Need n-i elements from right
            int j = n - i;

            for(int s1 : left[i]) {

                // We want s1 + s2 close to totalsum/2
                int target = totalsum / 2 - s1;

                auto it = lower_bound(
                    right[j].begin(),
                    right[j].end(),
                    target
                );

                // Candidate 1
                if(it != right[j].end()) {

                    int subsetSum = s1 + *it;

                    int difference =
                        abs(totalsum - 2 * subsetSum);

                    mini = min(mini, difference);
                }

                // Candidate 2
                if(it != right[j].begin()) {

                    --it;

                    int subsetSum = s1 + *it;

                    int difference =
                        abs(totalsum - 2 * subsetSum);

                    mini = min(mini, difference);
                }
            }
        }

        return mini;
    }
};