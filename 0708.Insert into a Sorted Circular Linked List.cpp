/**
 * @brief Insert into sorted circular linked list
 * @intuition Find correct position handling wrap-around at max/min boundary
 * @approach Traverse to find insertion point between prev and curr nodes
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static Node* insert(Node* head, const int insertVal) {
        auto* node = new Node(insertVal);
        if (!head) {
            node->next = node;
            return node;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        
        while (curr != head) {
            const bool inRange = prev->val <= insertVal && insertVal <= curr->val;
            const bool atBoundary = prev->val > curr->val && 
                                   (insertVal >= prev->val || insertVal <= curr->val);
            if (inRange || atBoundary) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = node;
        node->next = curr;
        return head;
    }
};
