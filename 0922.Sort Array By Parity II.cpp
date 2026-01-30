/**
 * @brief Sort array with even indices having even values
 * @intuition Swap misplaced elements at even and odd positions
 * @approach Two pointers: one for even indices, one for odd; swap when both wrong
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < static_cast<int>(nums.size()); i += 2) {
            if (nums[i] % 2) {
                while (nums[j] % 2) {
                    j += 2;
                }
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
