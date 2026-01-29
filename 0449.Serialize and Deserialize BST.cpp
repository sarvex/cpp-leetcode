/**
 * @brief Serialize and deserialize binary search tree
 * @intuition BST property allows reconstruction from preorder alone
 * @approach Preorder serialization, reconstruct using value bounds
 * @complexity Time: O(n) Space: O(n)
 */
#include <climits>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Codec final {
public:
    [[nodiscard]] auto serialize(TreeNode* root) const -> std::string {
        if (!root) {
            return "";
        }

        std::string data;
        std::function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            data += std::to_string(node->val) + " ";
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        data.pop_back();
        return data;
    }

    [[nodiscard]] auto deserialize(const std::string& data) const -> TreeNode* {
        if (data.empty()) {
            return nullptr;
        }

        std::vector<int> nums = split(data, ' ');
        std::size_t i = 0;

        std::function<TreeNode*(int, int)> dfs = [&](int mi, int mx) -> TreeNode* {
            if (i == nums.size() || nums[i] < mi || nums[i] > mx) {
                return nullptr;
            }
            const int x = nums[i++];
            auto* root = new TreeNode(x);
            root->left = dfs(mi, x);
            root->right = dfs(x, mx);
            return root;
        };

        return dfs(INT_MIN, INT_MAX);
    }

private:
    [[nodiscard]] static auto split(const std::string& s, char delim) -> std::vector<int> {
        std::vector<int> tokens;
        std::stringstream ss(s);
        std::string token;

        while (std::getline(ss, token, delim)) {
            tokens.push_back(std::stoi(token));
        }

        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
