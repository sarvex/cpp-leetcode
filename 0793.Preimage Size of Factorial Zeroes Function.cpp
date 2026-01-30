/**
 * @brief Count integers n where n! has exactly k trailing zeros
 * @intuition f(n) = trailing zeros is monotonic; binary search for range
 * @approach Find first n with >= k zeros, then >= k+1; difference is answer
 * @complexity Time: O(log^2 k), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int preimageSizeFZF(const int k) {
        return findFirst(k + 1) - findFirst(k);
    }

private:
    [[nodiscard]] static int findFirst(const int target) {
        long long left = 0;
        long long right = 5LL * target;
        
        while (left < right) {
            const long long mid = (left + right) >> 1;
            if (trailingZeros(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return static_cast<int>(left);
    }

    [[nodiscard]] static int trailingZeros(long long n) {
        int count = 0;
        while (n) {
            n /= 5;
            count += static_cast<int>(n);
        }
        return count;
    }
};
