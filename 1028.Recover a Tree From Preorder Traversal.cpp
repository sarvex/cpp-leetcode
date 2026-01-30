/**
 * @brief Stack-based tree reconstruction from depth-encoded string
 * @intuition Dashes indicate depth; numbers are node values
 * @approach Parse depth and value, maintain stack of ancestors, attach appropriately
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static TreeNode* recoverFromPreorder(const string& s) {
        stack<TreeNode*> st;
        int depth = 0;
        int num = 0;
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            if (s[i] == '-') {
                ++depth;
            } else {
                num = 10 * num + s[i] - '0';
            }
            if (i + 1 >= static_cast<int>(s.length()) || (isdigit(s[i]) && s[i + 1] == '-')) {
                auto* newNode = new TreeNode(num);
                while (st.size() > static_cast<size_t>(depth)) {
                    st.pop();
                }
                if (!st.empty()) {
                    if (st.top()->left == nullptr) {
                        st.top()->left = newNode;
                    } else {
                        st.top()->right = newNode;
                    }
                }
                st.push(newNode);
                depth = 0;
                num = 0;
            }
        }
        TreeNode* res = nullptr;
        while (!st.empty()) {
            res = st.top();
            st.pop();
        }
        return res;
    }
};
