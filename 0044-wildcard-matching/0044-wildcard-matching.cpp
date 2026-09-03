class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(m + 1, false)
        );

        // Both string and pattern are empty
        dp[0][0] = true;

        // Empty string with pattern
        // Only '*' can match an empty string
        for(int j = 1; j <= m; j++) {
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the table
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                // Same character OR '?'
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // '*'
                else if(p[j - 1] == '*') {

                    // '*' matches nothing
                    // OR
                    // '*' matches one/more characters
                    dp[i][j] =
                        dp[i][j - 1] ||
                        dp[i - 1][j];
                }

                // Different characters
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};