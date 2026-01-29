/**
 * @brief Detect cycle in linked list using hash set
 * @intuition If we visit a node twice, there's a cycle
 * @approach Track visited nodes in set, return true if duplicate found
 * @complexity Time: O(n), Space: O(n)
 */

#include <unordered_set>

using std::unordered_set;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution final {
public:
    [[nodiscard]] auto hasCycle(ListNode* head) const -> bool {
        unordered_set<ListNode*> visited;
        
        for (; head != nullptr; head = head->next) {
            if (visited.contains(head)) {
                return true;
            }
            visited.insert(head);
        }
        
        return false;
    }
};
