#include <random>
#include <unordered_map>
#include <vector>

/**
 * O(1) Insert/Delete/GetRandom with hash map and vector.
 * @intuition: Use a vector for random access and a hash map for index lookup.
 * @approach: Maintain a vector for values and a hash map from value to index.
 * Swap with last on remove.
 * @complexity: O(1) time and space per operation.
 */
class RandomizedSet final {
public:
  /**
   * @brief Constructs an empty set.
   * @param expectedSize Optionally reserve space for this many elements.
   */
  explicit RandomizedSet(size_t expectedSize = 0) {
    if (expectedSize)
      values.reserve(expectedSize);
  }

  /**
   * @brief Inserts a value if not present.
   * @intuition: Use emplace to avoid redundant lookups.
   * @approach: Insert with emplace and structured binding for efficiency.
   * @complexity: O(1) average time and space.
   * @param val The value to insert.
   * @return True if inserted, false if already present.
   */
  [[nodiscard]] bool insert(const int val) {
    auto [it, inserted] = indices.emplace(val, static_cast<int>(values.size()));
    if (!inserted) return false;
    values.push_back(val);
    return true;
  }

  /**
   * @brief Removes a value if present.
   * @intuition: Swap with last element only if not already last.
   * @approach: Use std::swap for vector and update index map accordingly.
   * @complexity: O(1) average time and space.
   * @param val The value to remove.
   * @return True if removed, false if not found.
   */
  [[nodiscard]] bool remove(const int val) {
    auto it = indices.find(val);
    if (it == indices.end()) return false;
    const int idx = it->second;
    if (idx != static_cast<int>(values.size()) - 1) {
      std::swap(values[idx], values.back());
      indices[values[idx]] = idx;
    }
    indices.erase(it);
    values.pop_back();
    return true;
  }

  /**
   * @brief Returns a random element from the set, or -1 if empty.
   * @intuition: Use a random index to select an element from the vector.
   * @approach: Use std::mt19937 and std::uniform_int_distribution for
   * randomness. Return -1 if the set is empty.
   * @complexity: O(1) time and space.
   * @return A random value from the set, or -1 if empty.
   */
  [[nodiscard]] int getRandom() const {
    if (values.empty())
      return -1;
    static thread_local std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<> dist(0,
                                         static_cast<int>(values.size()) - 1);
    return values[dist(gen)];
  }

private:
  std::unordered_map<int, int> indices;
  std::vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
