class Solution {
public:
    int minDistance(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // text2 is empty → delete all characters from text1
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        // text1 is empty → insert all characters of text2
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insert = 1 + dp[i][j - 1];
                    int deletee = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min(insert, min(deletee, replace));
                }
            }
        }

        return dp[n][m];
    }
};