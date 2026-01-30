/**
 * @brief Binary search on value range to find duplicate
 * @intuition Count elements <= mid, if count > mid, duplicate is in [1, mid]
 * @approach Binary search on answer space with counting
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int findDuplicate(const vector<int>& nums) {
        int left = 1;
        int right = static_cast<int>(nums.size()) - 1;
        
        while (left < right) {
            const int mid = (left + right) >> 1;
            int cnt = 0;
            for (const int v : nums) {
                cnt += (v <= mid);
            }
            if (cnt > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
