class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> Q;
        Q.push({root, 0});

        while (!Q.empty()) {
            int size = Q.size();
            long long min_index = Q.front().second;  // to normalize indices in each level
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto node_pair = Q.front();
                Q.pop();

                TreeNode* node = node_pair.first;
                long long index = node_pair.second - min_index; // normalize to avoid overflow

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node->left)
                    Q.push({node->left, 2 * index + 1});
                if (node->right)
                    Q.push({node->right, 2 * index + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return static_cast<int>(ans);
    }
};
