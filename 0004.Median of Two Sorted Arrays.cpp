#include <algorithm>
#include <limits>
#include <vector>

class Solution final {
public:
  /**
   * Find the median of two sorted arrays using binary search partitioning.
   * @intuition: Median is the middle value(s) after merging two sorted arrays.
   * @approach: Use an iterative k-th element search to avoid full merge.
   * @complexity: O(log(min(m, n))) time, O(1) space.
   */
  double findMedianSortedArrays(const std::vector<int> &first,
                                const std::vector<int> &second) const {
    const auto firstSize = std::ssize(first);
    const auto secondSize = std::ssize(second);

    const auto getKthSmallest = [&](int k) -> int {
      int firstIndex = 0, secondIndex = 0, remaining = k;

      while (true) {
        if (firstIndex == firstSize)
          return second[secondIndex + remaining - 1];
        if (secondIndex == secondSize)
          return first[firstIndex + remaining - 1];
        if (remaining == 1)
          return std::min(first[firstIndex], second[secondIndex]);

        const int step = remaining / 2;
        const int newFirstIndex =
            std::min(firstIndex + step, static_cast<int>(firstSize));
        const int newSecondIndex =
            std::min(secondIndex + step, static_cast<int>(secondSize));
        const int firstValue = (newFirstIndex - 1 < firstSize)
                                   ? first[newFirstIndex - 1]
                                   : std::numeric_limits<int>::max();
        const int secondValue = (newSecondIndex - 1 < secondSize)
                                    ? second[newSecondIndex - 1]
                                    : std::numeric_limits<int>::max();

        if (firstValue < secondValue) {
          remaining -= (newFirstIndex - firstIndex);
          firstIndex = newFirstIndex;
        } else {
          remaining -= (newSecondIndex - secondIndex);
          secondIndex = newSecondIndex;
        }
      }
    };

    const int totalSize = firstSize + secondSize;
    const int leftMedian = getKthSmallest((totalSize + 1) / 2);
    const int rightMedian = getKthSmallest((totalSize + 2) / 2);
    return (leftMedian + rightMedian) / 2.0;
  }
};
