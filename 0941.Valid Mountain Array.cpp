/**
 * @brief Check if array forms a valid mountain
 * @intuition Find peak by climbing from both ends; must meet at same point
 * @approach Two pointers from both ends climb up; check if they meet and not at edges
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool validMountainArray(const vector<int>& arr) {
        const int n = static_cast<int>(arr.size());
        if (n < 3) {
            return false;
        }
        int i = 0, j = n - 1;
        while (i + 1 < n - 1 && arr[i] < arr[i + 1]) {
            ++i;
        }
        while (j - 1 > 0 && arr[j - 1] > arr[j]) {
            --j;
        }
        return i == j;
    }
};
