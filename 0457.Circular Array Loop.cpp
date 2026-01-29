/**
 * @brief Detect cycle in circular array with all same direction moves
 * @intuition Floyd's cycle detection, mark visited paths
 * @approach For each start, use slow/fast pointers, validate cycle direction
 * @complexity Time: O(n) Space: O(1)
 */
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto circularArrayLoop(std::vector<int>& nums) const -> bool {
        const int n = static_cast<int>(nums.size());

        auto next = [&](int i) {
            return ((i + nums[i]) % n + n) % n;
        };

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }

            int slow = i;
            int fast = next(i);

            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    }
                    break;
                }
                slow = next(slow);
                fast = next(next(fast));
            }

            int j = i;
            while (nums[j] * nums[next(j)] > 0) {
                const int tmp = j;
                j = next(j);
                nums[tmp] = 0;
            }
        }

        return false;
    }
};
