#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        
        // Step 1: Find the minimum odd number in nums1
        for (int x : nums1) {
            if (x % 2 != 0) {
                minOdd = min(minOdd, x);
            }
        }
        
        // Step 2: Check if any even number is smaller than the minimum odd number
        for (int x : nums1) {
            if (x % 2 == 0 && minOdd != INT_MAX && x < minOdd) {
                return false;
            }
        }
        
        return true;
    }
};