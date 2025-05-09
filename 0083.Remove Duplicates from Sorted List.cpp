/**
 * @brief In-place deletion of duplicates in a sorted linked list using single-pass traversal
 *
 * @intuition Since the list is sorted, duplicates will be adjacent. We can traverse once,
 * comparing current node with next and skip duplicates by adjusting pointers.
 *
 * @approach
 * - Use a pointer to traverse the list
 * - Compare each node with its next node
 * - If values are equal, skip the next node by adjusting pointers
 * - If not equal, move to next node
 * - Memory is automatically managed as nodes are part of input
 *
 * @complexity
 * Time: O(n) where n is the number of nodes
 * Space: O(1) as we only use a single pointer
 */

struct ListNode {
    int val;
    ListNode* next;
    constexpr ListNode() noexcept : val(0), next(nullptr) {}
    constexpr explicit ListNode(int x) noexcept : val(x), next(nullptr) {}
    constexpr ListNode(int x, ListNode* next) noexcept : val(x), next(next) {}
};

class Solution {
public:
    [[nodiscard]] ListNode* deleteDuplicates(ListNode* head) noexcept {
        if (!head || !head->next) return head;  // Handle empty or single-node list

        auto current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                auto duplicate = current->next;
                current->next = duplicate->next;  // Skip duplicate node
                // Note: In LeetCode environment, we don't delete nodes as they're managed by the system
            } else {
                current = current->next;  // Move to next distinct value
            }
        }

        return head;
    }
};
