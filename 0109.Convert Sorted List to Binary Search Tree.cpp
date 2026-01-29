/**
 * @brief Build height-balanced BST from sorted linked list
 * @intuition Convert list to array first, then use array-based BST construction
 * @approach Collect values in vector, then recursively build BST from middle elements
 * @complexity Time: O(n), Space: O(n)
 */

#include <vector>

using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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

class Solution final {
public:
    [[nodiscard]] auto sortedListToBST(ListNode* head) const -> TreeNode* {
        vector<int> nums;
        for (; head != nullptr; head = head->next) {
            nums.push_back(head->val);
        }
        
        auto dfs = [&](this auto&& dfs, int left, int right) -> TreeNode* {
            if (left > right) {
                return nullptr;
            }
            const int mid = left + (right - left) / 2;
            auto* leftTree = dfs(left, mid - 1);
            auto* rightTree = dfs(mid + 1, right);
            return new TreeNode(nums[mid], leftTree, rightTree);
        };
        
        return dfs(0, static_cast<int>(nums.size()) - 1);
    }
};
