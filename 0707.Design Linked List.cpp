/**
 * @brief Singly linked list with dummy head implementation
 * @intuition Dummy head simplifies edge cases for insertion and deletion
 * @approach Maintain count and traverse to index for operations
 * @complexity Time: O(n) for get/add/delete, Space: O(n)
 */
class MyLinkedList final {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x = 0, ListNode* n = nullptr) : val(x), next(n) {}
    };

public:
    MyLinkedList() : dummy_(new ListNode()), count_(0) {}

    [[nodiscard]] int get(int index) const {
        if (index < 0 || index >= count_) {
            return -1;
        }
        auto cur = dummy_->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(const int val) {
        addAtIndex(0, val);
    }

    void addAtTail(const int val) {
        addAtIndex(count_, val);
    }

    void addAtIndex(int index, const int val) {
        if (index > count_) {
            return;
        }
        auto prev = dummy_;
        while (index-- > 0) {
            prev = prev->next;
        }
        prev->next = new ListNode(val, prev->next);
        ++count_;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= count_) {
            return;
        }
        auto prev = dummy_;
        while (index-- > 0) {
            prev = prev->next;
        }
        auto toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        --count_;
    }

private:
    ListNode* dummy_;
    int count_;
};
