/**
 * @brief Return random node value from linked list using reservoir sampling
 * @intuition Reservoir sampling gives equal probability without knowing length
 * @approach For ith element, replace result with probability 1/i
 * @complexity Time: O(n) per call, Space: O(1)
 */
class Solution final {
public:
    explicit Solution(ListNode* head) : head_(head) {}

    [[nodiscard]] auto getRandom() const -> int {
        int n = 0;
        int ans = 0;
        for (ListNode* node = head_; node != nullptr; node = node->next) {
            ++n;
            if (rand() % n == 0) {
                ans = node->val;
            }
        }
        return ans;
    }

private:
    ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
