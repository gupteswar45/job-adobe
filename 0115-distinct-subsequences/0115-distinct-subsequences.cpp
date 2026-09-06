class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<unsigned long long>> dp(n + 1,
            vector<unsigned long long>(m + 1, 0));

        // Empty t can be formed in exactly 1 way
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;

            for (int j = 1; j <= m; j++) {

                // Don't take s[i-1]
                dp[i][j] = dp[i - 1][j];

                // Take s[i-1] if characters match
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};