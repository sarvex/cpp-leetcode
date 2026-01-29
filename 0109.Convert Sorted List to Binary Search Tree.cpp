/**
 * @brief Build height-balanced BST from sorted linked list
 * @intuition Convert list to array first, then use array-based BST construction
 * @approach Collect values in vector, then recursively build BST from middle elements
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
    [[nodiscard]] static auto sortedListToBST(ListNode* head) -> TreeNode* {
        std::vector<int> nums;
        for (; head != nullptr; head = head->next) {
            nums.push_back(head->val);
        }
        
        auto dfs = [&](this auto&& self, int left, int right) -> TreeNode* {
            if (left > right) {
                return nullptr;
            }
            const int mid = left + (right - left) / 2;
            auto* leftTree = self(left, mid - 1);
            auto* rightTree = self(mid + 1, right);
            return new TreeNode(nums[mid], leftTree, rightTree);
        };
        
        return dfs(0, static_cast<int>(nums.size()) - 1);
    }
};
