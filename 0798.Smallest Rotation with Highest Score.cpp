/**
 * @brief Find rotation giving maximum score (element <= index counts)
 * @intuition Use difference array to track score changes across rotations
 * @approach For each element, compute valid k range, use difference array
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int bestRotation(const std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int maxScore = -1;
        int bestK = n;
        std::vector<int> diff(n, 0);
        
        for (int i = 0; i < n; ++i) {
            const int left = (i + 1) % n;
            const int right = (n + i + 1 - nums[i]) % n;
            ++diff[left];
            --diff[right];
        }
        
        int score = 0;
        for (int k = 0; k < n; ++k) {
            score += diff[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }
        return bestK;
    }
};
