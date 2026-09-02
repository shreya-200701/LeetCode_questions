class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        
        vector<vector<int>> dp(
            text1.length() + 1,
            vector<int>(text2.length() + 1, 0)
        );

        // LCS DP
        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";

        int i = text1.length();
        int j = text2.length();

        // Reconstruct SCS
        while (i > 0 && j > 0) {

            // SAME CHARACTER
            if (text1[i - 1] == text2[j - 1]) {
                ans += text1[i - 1];
                i--;
                j--;
            }

            // Take character from text1
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += text1[i - 1];
                i--;
            }

            // Take character from text2
            else {
                ans += text2[j - 1];
                j--;
            }
        }

        // Remaining characters of text1
        while (i > 0) {
            ans += text1[i - 1];
            i--;
        }

        // Remaining characters of text2
        while (j > 0) {
            ans += text2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};