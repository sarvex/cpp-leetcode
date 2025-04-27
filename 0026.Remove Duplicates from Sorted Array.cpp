class Solution {
public:
  /**
   * Removes duplicates from a sorted array in-place such that each element
   * appears only once.
   *
   * @param nums Reference to a vector of sorted integers. The function modifies
   * this vector in-place.
   * @return The number of unique elements after removing duplicates.
   */
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty())
      return 0;
    int i = 0;
    const int size = nums.size();
    for (int j = 1; j < size; ++j) {
      if (nums[j] != nums[i]) {
        ++i;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};
