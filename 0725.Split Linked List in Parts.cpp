/**
 * @brief Split linked list into k parts with even distribution
 * @intuition First parts get one extra node if n % k > 0
 * @approach Count length, calculate part sizes, split accordingly
 * @complexity Time: O(n), Space: O(k) for result array
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<ListNode*> splitListToParts(ListNode* head, const int k) {
        int length = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            ++length;
        }
        
        const int partSize = length / k;
        int extraNodes = length % k;
        std::vector<ListNode*> result(k, nullptr);
        ListNode* cur = head;
        
        for (int i = 0; i < k && cur; ++i) {
            result[i] = cur;
            const int currentPartSize = partSize + (extraNodes-- > 0 ? 1 : 0);
            for (int j = 1; j < currentPartSize; ++j) {
                cur = cur->next;
            }
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        return result;
    }
};
