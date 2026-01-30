/**
 * @brief Iterator over run-length encoded sequence
 * @intuition Track current position in encoding; skip runs as needed
 * @approach Maintain index in encoding and offset within current run. For each next(n),
 *           consume n elements, advancing through runs as needed.
 * @complexity Time: O(n) amortized per next, Space: O(1)
 */
class RLEIterator final {
    std::vector<int> encoding;
    std::size_t i = 0;
    int j = 0;

public:
    explicit RLEIterator(const std::vector<int>& encoding) : encoding(encoding) {}

    [[nodiscard]] auto next(int n) -> int {
        while (i < encoding.size()) {
            if (encoding[i] - j < n) {
                n -= (encoding[i] - j);
                i += 2;
                j = 0;
            } else {
                j += n;
                return encoding[i + 1];
            }
        }
        return -1;
    }
};
