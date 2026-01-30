/**
 * @brief Count connected components in linked list subset
 * @intuition A component starts when entering subset and ends when leaving
 * @approach Use hash set for O(1) subset membership check. Traverse list,
 *           counting transitions from non-subset to subset nodes.
 * @complexity Time: O(n), Space: O(m) where m is subset size
 */
class Solution final {
public:
    [[nodiscard]] static auto numComponents(ListNode* head,
                                             const std::vector<int>& nums) -> int {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        
        while (head) {
            while (head && !s.count(head->val)) {
                head = head->next;
            }
            ans += (head != nullptr);
            while (head && s.count(head->val)) {
                head = head->next;
            }
        }
        return ans;
    }
};
