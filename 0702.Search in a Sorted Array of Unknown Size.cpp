/**
 * @brief Binary search with exponential bound finding
 * @intuition First find upper bound exponentially, then binary search within range
 * @approach Double right bound until target found, then apply standard binary search
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int search(const ArrayReader& reader, const int target) {
        int right = 1;
        while (reader.get(right) < target) {
            right <<= 1;
        }
        int left = right >> 1;
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (reader.get(mid) >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return reader.get(left) == target ? left : -1;
    }
};
