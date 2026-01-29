/**
 * @brief Count tuples (i,j,k,l) where A[i]+B[j]+C[k]+D[l]=0
 * @intuition Pair first two arrays, pair last two arrays, find complement
 * @approach Store sums of A+B in map, count matching -(C+D) sums
 * @complexity Time: O(n^2) Space: O(n^2)
 */
#include <unordered_map>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto fourSumCount(const std::vector<int>& nums1, const std::vector<int>& nums2,
                                     const std::vector<int>& nums3, const std::vector<int>& nums4) const -> int {
        std::unordered_map<int, int> cnt;

        for (const int a : nums1) {
            for (const int b : nums2) {
                ++cnt[a + b];
            }
        }

        int ans = 0;
        for (const int c : nums3) {
            for (const int d : nums4) {
                if (auto it = cnt.find(-(c + d)); it != cnt.end()) {
                    ans += it->second;
                }
            }
        }

        return ans;
    }
};
