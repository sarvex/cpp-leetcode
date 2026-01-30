/**
 * @brief Level-order serialization/deserialization of binary tree
 * @intuition BFS traversal with null markers for missing children
 * @approach Serialize: BFS with "#" for null; Deserialize: BFS reconstruction
 * @complexity Time: O(n), Space: O(n)
 */
class Codec final {
public:
    [[nodiscard]] static string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        queue<TreeNode*> q{{root}};
        string ans;
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node != nullptr) {
                ans += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "# ";
            }
        }
        ans.pop_back();
        return ans;
    }

    [[nodiscard]] static TreeNode* deserialize(const string& data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream ss(data);
        string token;
        ss >> token;
        
        auto* root = new TreeNode(stoi(token));
        queue<TreeNode*> q{{root}};
        
        while (!q.empty()) {
            auto* node = q.front();
            q.pop();
            
            ss >> token;
            if (token != "#") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            
            ss >> token;
            if (token != "#") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};
