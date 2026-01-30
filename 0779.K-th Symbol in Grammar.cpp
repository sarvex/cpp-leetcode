/**
 * @brief Find k-th symbol in grammar sequence
 * @intuition Each row doubles; first half same as parent, second half flipped
 * @approach Recursive: if k in first half, recurse; else flip result of second half
 * @complexity Time: O(n), Space: O(n) for recursion
 */
class Solution final {
public:
    [[nodiscard]] static int kthGrammar(const int n, const int k) {
        if (n == 1) return 0;
        const int half = 1 << (n - 2);
        if (k <= half) {
            return kthGrammar(n - 1, k);
        }
        return kthGrammar(n - 1, k - half) ^ 1;
    }
};
