/**
 * @brief Prefix and suffix search using hash map
 * @intuition Precompute all prefix-suffix combinations for each word
 * @approach Store all prefix.suffix combinations with word index in map
 * @complexity Time: O(n*L^2) for init, O(1) for query, Space: O(n*L^2)
 */
class WordFilter final {
public:
    explicit WordFilter(const std::vector<std::string>& words) {
        for (int k = 0; k < static_cast<int>(words.size()); ++k) {
            const auto& word = words[k];
            const int len = static_cast<int>(word.size());
            for (int i = 0; i <= len; ++i) {
                std::string prefix = word.substr(0, i);
                for (int j = 0; j <= len; ++j) {
                    std::string suffix = word.substr(j);
                    lookup_[prefix + "." + suffix] = k;
                }
            }
        }
    }

    [[nodiscard]] int f(const std::string& pref, const std::string& suff) const {
        const std::string key = pref + "." + suff;
        auto it = lookup_.find(key);
        return it != lookup_.end() ? it->second : -1;
    }

private:
    std::unordered_map<std::string, int> lookup_;
};
