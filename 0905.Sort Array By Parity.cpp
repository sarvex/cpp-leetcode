/**
 * @brief Two-pointer in-place array partitioning by parity
 * @intuition Place even numbers at front, odd at back
 * @approach Use two pointers from both ends; swap when left is odd and right is even
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = static_cast<int>(nums.size()) - 1;
        while (i < j) {
            if (nums[i] % 2 == 0) {
                ++i;
            } else if (nums[j] % 2 == 1) {
                --j;
            } else {
                swap(nums[i++], nums[j--]);
            }
        }
        return nums;
    }
};
