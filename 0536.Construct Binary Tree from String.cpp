/**
 * @brief Construct binary tree from string with nested parentheses
 * @intuition Parse number for root, then recursively parse parenthesized subtrees
 * @approach Find first '(' to separate root value. Track parenthesis balance to find
 *           left subtree end. Recursively build left and right children from substrings.
 * @complexity Time: O(n^2) due to substring operations, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto str2tree(const string& s) -> TreeNode* {
        return dfs(s);
    }

private:
    [[nodiscard]] static auto dfs(const string& s) -> TreeNode* {
        if (s.empty()) return nullptr;
        
        const auto p = s.find('(');
        if (p == string::npos) {
            return new TreeNode(stoi(s));
        }
        
        auto* root = new TreeNode(stoi(s.substr(0, p)));
        auto start = p;
        int balance = 0;
        
        for (size_t i = p; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++balance;
            } else if (s[i] == ')') {
                --balance;
            }
            
            if (balance == 0) {
                if (start == p) {
                    root->left = dfs(s.substr(start + 1, i - start - 1));
                    start = i + 1;
                } else {
                    root->right = dfs(s.substr(start + 1, i - start - 1));
                }
            }
        }
        return root;
    }
};
