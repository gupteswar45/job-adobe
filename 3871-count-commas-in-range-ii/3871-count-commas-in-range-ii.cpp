class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        
        // Commas appear at powers of 1000
        for (long long threshold = 1000; threshold <= n; threshold *= 1000) {
            totalCommas += (n - threshold + 1);
            
            // Prevent 64-bit signed integer overflow when multiplying threshold by 1000
            if (threshold > LLONG_MAX / 1000) {
                break;
            }
        }
        
        return totalCommas;
    }
};