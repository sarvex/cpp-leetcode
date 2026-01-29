/**
 * @brief Find nth super ugly number using min-heap
 * @intuition Generate ugly numbers in order using priority queue
 * @approach Use min-heap to always get the smallest next ugly number
 * @complexity Time: O(n * k * log(nk)), Space: O(nk)
 */
#include <climits>
#include <functional>
#include <queue>
#include <vector>

class Solution final {
public:
    [[nodiscard]] int nthSuperUglyNumber(int n, const std::vector<int>& primes) const {
        std::priority_queue<int, std::vector<int>, std::greater<>> pq;
        pq.push(1);
        int x = 0;
        
        while (n-- > 0) {
            x = pq.top();
            pq.pop();
            
            for (const int k : primes) {
                if (x <= INT_MAX / k) {
                    pq.push(k * x);
                }
                if (x % k == 0) {
                    break;
                }
            }
        }
        return x;
    }
};
