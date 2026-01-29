# LeetCode C++26 Solutions Guidelines

## Purpose

Generate clean, performant LeetCode solutions using modern C++26. Minimize verbosity. Prioritize correctness, readability, and optimal complexity.

## File Naming

- Use the problem number and name: `0001-two-sum.cpp`
- All lowercase with hyphens

## Solution Structure

All solutions must use LeetCode's expected class:

```cpp
class Solution {
public:
    ReturnType functionName(Parameters) {
        // implementation
    }
};
```

## Documentation Format

Every solution must have a Doxygen header:

```cpp
/**
 * @brief [One-line approach description]
 *
 * @intuition [First thoughts on solving this problem]
 *
 * @approach [Detailed explanation of the algorithm]
 *
 * @complexity
 * Time: O(...)
 * Space: O(...)
 */
```

## C++26 Style

### Prefer
- `const` / `constexpr` / `consteval` by default
- Range-based for loops and STL algorithms over raw loops
- `std::span`, `std::ranges`, `std::views` pipelines
- Structured bindings and pattern matching
- Smart pointers over raw pointers (when needed)
- `auto` with meaningful context
- Early returns to reduce nesting
- Lambdas for local operations
- `std::expected` for error handling
- `std::print` / `std::println` over iostream (for debugging)
- Reflection features where applicable

### Avoid
- Raw pointers and manual memory management
- Unnecessary copies (use move semantics)
- Macros (prefer `constexpr` / inline functions)
- Abbreviations (except universally known: `i`, `n`, `dp`)
- Old-style casts (use `static_cast`, `std::bit_cast`)

## Naming Conventions

| Element      | Style        | Example              |
|--------------|--------------|----------------------|
| Variables    | camelCase    | `leftPointer`        |
| Functions    | camelCase    | `findMaxSum`         |
| Types/Classes| PascalCase   | `TreeNode`           |
| Constants    | UPPER_CASE   | `MAX_SIZE`           |

## Common Patterns

Be familiar with and apply these idioms:
- Two pointers / Sliding window
- Binary search variations
- DFS/BFS traversal
- Dynamic programming (top-down, bottom-up)
- Monotonic stack/queue
- Union-Find
- Trie
- Segment tree / Fenwick tree

## Optimization Priorities

1. Correctness first
2. Optimal time complexity
3. Optimal space complexity
4. Code clarity

## What NOT To Do

- Do not add test harnesses (LeetCode provides these)
- Do not create multi-file solutions
- Do not add `main()` functions unless explicitly requested
- Do not include unnecessary headers
- Do not write verbose explanations outside the doc header
