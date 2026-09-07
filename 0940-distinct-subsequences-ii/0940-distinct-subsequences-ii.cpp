class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<int> dp(26, 0);
        long long ans = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            long long add = (ans - dp[idx] + 1 + MOD) % MOD;
            ans = (ans + add) % MOD;
            dp[idx] = (dp[idx] + add) % MOD;
        }
        
        return ans;
    }
};
