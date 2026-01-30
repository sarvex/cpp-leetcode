/**
 * @brief Merge two quad-trees with logical OR operation
 * @intuition If either leaf is true, result is true leaf; otherwise recurse and possibly simplify
 * @approach DFS merge: handle leaf cases, recurse on children, collapse if all children same leaf
 * @complexity Time: O(n), Space: O(log n) where n is number of nodes
 */
class Solution final {
public:
    [[nodiscard]] static Node* intersect(Node* quadTree1, Node* quadTree2) {
        return merge(quadTree1, quadTree2);
    }

private:
    [[nodiscard]] static Node* merge(Node* t1, Node* t2) {
        if (t1->isLeaf && t2->isLeaf) {
            return new Node(t1->val || t2->val, true);
        }
        if (t1->isLeaf) {
            return t1->val ? t1 : t2;
        }
        if (t2->isLeaf) {
            return t2->val ? t2 : t1;
        }
        
        auto* result = new Node();
        result->topLeft = merge(t1->topLeft, t2->topLeft);
        result->topRight = merge(t1->topRight, t2->topRight);
        result->bottomLeft = merge(t1->bottomLeft, t2->bottomLeft);
        result->bottomRight = merge(t1->bottomRight, t2->bottomRight);
        
        const bool allLeaves = result->topLeft->isLeaf && result->topRight->isLeaf &&
                               result->bottomLeft->isLeaf && result->bottomRight->isLeaf;
        const bool sameValue = result->topLeft->val == result->topRight->val &&
                               result->topRight->val == result->bottomLeft->val &&
                               result->bottomLeft->val == result->bottomRight->val;
        
        if (allLeaves && sameValue) {
            return result->topLeft;
        }
        
        return result;
    }
};
