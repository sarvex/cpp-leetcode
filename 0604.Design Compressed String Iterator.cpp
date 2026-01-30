/**
 * @brief Iterator for compressed string with run-length encoding
 * @intuition Parse compressed string into character-count pairs, then iterate
 * @approach Store pairs of (character, count), decrement count on each next() call
 * @complexity Time: O(n) for construction, O(1) per operation, Space: O(n)
 */
class StringIterator final {
public:
    explicit StringIterator(const string& compressedString) {
        const int n = compressedString.size();
        int i = 0;
        while (i < n) {
            const char c = compressedString[i];
            int x = 0;
            while (++i < n && isdigit(compressedString[i])) {
                x = x * 10 + (compressedString[i] - '0');
            }
            d_.emplace_back(c, x);
        }
    }

    [[nodiscard]] char next() {
        if (!hasNext()) {
            return ' ';
        }
        const char ans = d_[p_].first;
        if (--d_[p_].second == 0) {
            ++p_;
        }
        return ans;
    }

    [[nodiscard]] bool hasNext() const {
        return p_ < d_.size() && d_[p_].second > 0;
    }

private:
    vector<pair<char, int>> d_;
    size_t p_ = 0;
};
