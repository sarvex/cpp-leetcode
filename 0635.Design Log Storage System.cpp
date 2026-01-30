/**
 * @brief Log storage system with timestamp-based retrieval
 * @intuition Store logs with timestamps, filter by prefix based on granularity
 * @approach Compare timestamp prefixes of appropriate length for each granularity
 * @complexity Time: O(n) per retrieve, Space: O(n)
 */
class LogSystem final {
public:
    LogSystem() {
        d_["Year"] = 4;
        d_["Month"] = 7;
        d_["Day"] = 10;
        d_["Hour"] = 13;
        d_["Minute"] = 16;
        d_["Second"] = 19;
    }

    void put(const int id, const string& timestamp) {
        logs_.emplace_back(id, timestamp);
    }

    [[nodiscard]] vector<int> retrieve(const string& start, const string& end, const string& granularity) const {
        vector<int> ans;
        const int i = d_.at(granularity);
        const auto s = start.substr(0, i);
        const auto e = end.substr(0, i);
        
        for (const auto& [id, ts] : logs_) {
            const auto t = ts.substr(0, i);
            if (s <= t && t <= e) {
                ans.push_back(id);
            }
        }
        return ans;
    }

private:
    vector<pair<int, string>> logs_;
    unordered_map<string, int> d_;
};
