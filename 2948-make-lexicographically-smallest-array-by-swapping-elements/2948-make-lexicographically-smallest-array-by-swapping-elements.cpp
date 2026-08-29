#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Store (value, original_index) pairs
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
        // Sort pairs primarily by value
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> result(n);
        
        // Process in connected groups
        int i = 0;
        while (i < n) {
            int j = i;
            
            // Find the boundary of the current group where adjacent differences <= limit
            while (j + 1 < n && sorted_nums[j + 1].first - sorted_nums[j].first <= limit) {
                j++;
            }
            
            // Collect indices for the current group
            vector<int> indices;
            for (int k = i; k <= j; ++k) {
                indices.push_back(sorted_nums[k].second);
            }
            
            // Sort indices to place values in leftmost available positions
            sort(indices.begin(), indices.end());
            
            // Assign sorted values to sorted indices
            for (int k = i; k <= j; ++k) {
                result[indices[k - i]] = sorted_nums[k].first;
            }
            
            // Move to the next group
            i = j + 1;
        }
        
        return result;
    }
};