/**
 * @brief Find kth smallest number in lexicographical order from 1 to n
 * @intuition Numbers form a trie, count children in each prefix subtree
 * @approach Start from 1, either go to next sibling or first child based on k
 * @complexity Time: O(log^2 n) Space: O(1)
 */
#include <algorithm>

class Solution final {
public:
    [[nodiscard]] auto findKthNumber(int n, int k) const -> int {
        --k;
        long long curr = 1;

        while (k > 0) {
            const int cnt = count(curr, n);
            if (k >= cnt) {
                k -= cnt;
                ++curr;
            } else {
                --k;
                curr *= 10;
            }
        }

        return static_cast<int>(curr);
    }

private:
    [[nodiscard]] static auto count(long long curr, int n) -> int {
        long long next = curr + 1;
        int cnt = 0;

        while (curr <= n) {
            cnt += static_cast<int>(std::min(static_cast<long long>(n) - curr + 1, next - curr));
            next *= 10;
            curr *= 10;
        }

        return cnt;
    }
};
