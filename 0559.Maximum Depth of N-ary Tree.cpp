/**
 * @brief Find maximum depth of N-ary tree using DFS
 * @intuition Depth is 1 plus maximum depth among all children
 * @approach Recursively compute max child depth, add 1 for current node
 * @complexity Time: O(n), Space: O(h) where h is tree height
 */
class Solution final {
public:
    [[nodiscard]] static int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        
        int maxChildDepth = 0;
        for (Node* child : root->children) {
            maxChildDepth = max(maxChildDepth, maxDepth(child));
        }
        
        return maxChildDepth + 1;
    }
};
