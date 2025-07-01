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
public:
    vector<int> rightSideView(TreeNode* root) {
         if (!root) return {};

        map<int, int> levelMap; // map to store rightmost node at each level
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0}); // start with the root at level 0

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            // Insert the rightmost node for this level
            if (levelMap.find(level) == levelMap.end()) {
                levelMap[level] = node->val;
            }

            // Process the right child first
            if (node->right) {
                q.push({node->right, level + 1});
            }
            // Then process the left child
            if (node->left) {
                q.push({node->left, level + 1});
            }
        }

        // Extract the result from the map
        vector<int> res;
        for (auto [level, val] : levelMap) {
            res.push_back(val);
        }

        return res;
    }
};