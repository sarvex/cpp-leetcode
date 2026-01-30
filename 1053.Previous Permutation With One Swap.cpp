/**
 * @brief Find largest permutation smaller than current with one swap
 * @intuition Find rightmost decreasing pair, swap with largest smaller element
 * @approach Scan right to left for decrease, find optimal swap candidate
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> prevPermOpt1(vector<int>& arr) {
        const int n = arr.size();
        for (int i = n - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                for (int j = n - 1; j > i - 1; --j) {
                    if (arr[j] < arr[i - 1] && arr[j] != arr[j - 1]) {
                        swap(arr[i - 1], arr[j]);
                        return arr;
                    }
                }
            }
        }
        return arr;
    }
};
