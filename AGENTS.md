# Agent Instructions

This repository contains C++26 LeetCode solutions. See `.github/copilot-instructions.md` for full style guidelines.

## Quick Reference

**Solution format:**
```cpp
class Solution {
public:
    /**
     * @brief [Approach in one line]
     * @intuition [Initial problem analysis]
     * @approach [Algorithm explanation]
     * @complexity Time: O(...) Space: O(...)
     */
    ReturnType functionName(Parameters) {
        // Modern C++23, clean, performant
    }
};
```

**Style:** C++26, `const`/`constexpr`/`consteval` by default, ranges, structured bindings, `std::expected`, no raw pointers, early returns.

**Do NOT:** Add `main()`, test harnesses, multi-file solutions, or verbose inline comments.
