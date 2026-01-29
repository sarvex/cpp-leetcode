/**
 * @brief Rotate array using reversal algorithm
 * @intuition Three reversals achieve rotation without extra space
 * @approach Reverse entire array, reverse first k, reverse rest
 * @complexity Time: O(n), Space: O(1)
 */

class Solution final {
public:
    static auto rotate(std::vector<int>& nums, int k) -> void {
        const int n = static_cast<int>(nums.size());
        if (n == 0 || k % n == 0) {
            return;
        }
        k = k % n;
        std::ranges::reverse(nums);
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
