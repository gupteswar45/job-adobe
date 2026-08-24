class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sum
        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // Start from n-2 because at least 2 stones
        // must be taken in the first move.
        int dp = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};