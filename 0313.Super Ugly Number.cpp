/**
 * @brief Find nth super ugly number using min-heap
 * @intuition Generate ugly numbers in order using priority queue
 * @approach Use min-heap to always get the smallest next ugly number
 * @complexity Time: O(n * k * log(nk)), Space: O(nk)
 */
class Solution final {
public:
    [[nodiscard]] static int nthSuperUglyNumber(int n, const vector<int>& primes) {
        priority_queue<int, vector<int>, greater<>> pq;
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
