
class Solution {
public:
    bool checkpalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int f(string& s, int i, vector<int>& dp) {
        int n = s.length();

        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int mini = INT_MAX;

        for (int j = i; j < n; j++) {
            if (checkpalindrome(s, i, j)) {
                int count = 1 + f(s, j + 1, dp);
                mini = min(mini, count);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);

        return f(s, 0, dp) - 1;
    }
};