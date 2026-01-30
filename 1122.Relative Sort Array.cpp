/**
 * @brief Sort arr1 according to order defined in arr2, remaining elements in ascending order
 * @intuition Map arr2 elements to priority indices, elements not in arr2 get lowest priority
 * @approach Create position map from arr2. Sort arr1 by (position, value) pairs where elements
 *           not in arr2 have position = arr2.size() to appear at end sorted by value.
 * @complexity Time: O(n log n), Space: O(n + m) where m is arr2 size
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> relativeSortArray(vector<int>& arr1, const vector<int>& arr2) {
        unordered_map<int, int> pos;
        for (int i = 0; i < arr2.size(); ++i) {
            pos[arr2[i]] = i;
        }
        vector<pair<int, int>> arr;
        for (int i = 0; i < arr1.size(); ++i) {
            int j = pos.count(arr1[i]) ? pos[arr1[i]] : arr2.size();
            arr.emplace_back(j, arr1[i]);
        }
        ranges::sort(arr);
        for (int i = 0; i < arr1.size(); ++i) {
            arr1[i] = arr[i].second;
        }
        return arr1;
    }
};
