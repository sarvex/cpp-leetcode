
#include <vector>
using namespace std;

class Solution {
public:
  // Uses Boyer-Moore Voting Algorithm to find the majority element in linear
  // time and constant space.
  int majorityElement(vector<int> &nums) {
    int candidate = 0;
    int count = 0;
    for (int number : nums) {
      if (count == 0) {
        candidate = number;
        count = 1;
      } else {
        count += (number == candidate) ? 1 : -1;
      }
    }
    return candidate;
  }
};
