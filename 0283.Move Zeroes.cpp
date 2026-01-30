/**
 * @brief Two-pointer approach to move zeroes to end
 * @intuition Swap non-zero elements to front, keeping relative order
 * @approach Use write pointer k, swap non-zero elements forward
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    static void moveZeroes(vector<int>& nums) {
        int k = 0;
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[k++]);
            }
        }
    }
};
