#include <iostream>
#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int matchingNodesCount = 0;

    // Returns a pair: {Sum of subtree, Total count of nodes in subtree}
    std::pair<int, int> postOrder(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        // Post-order traversal: Left -> Right -> Node
        auto left = postOrder(root->left);
        auto right = postOrder(root->right);

        int currentSum = root->val + left.first + right.first;
        int currentCount = 1 + left.second + right.second;

        // Check if floor average equals current node's value
        if (currentSum / currentCount == root->val) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0;
        postOrder(root);
        return matchingNodesCount;
    }
};