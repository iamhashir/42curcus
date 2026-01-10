# CPP Module 09 - PmergeMe

> **How I conquered Merge-Insertion Sort (Ford-Johnson) without losing my sanity**

This README is not just what I implemented - it is how I understood, modeled, visualized, and justified every decision required to pass **CPP09 / ex02 (PmergeMe)**.

The notes below follow the same cognitive order I used to master the algorithm, with direct pointers to the implementation in `ex02/PmergeMe.cpp` and `ex02/PmergeMe.hpp`.

---

## 1. The Goal (Why this even exists)

**Minimize the maximum number of comparisons.**

Not Big-O marketing. Not averages. Worst-case comparisons.

Ford-Johnson (Merge-Insertion Sort) is optimal for small-medium `n`. The Jacobsthal sequence is the scheduler that makes this possible.

---

## 2. Code Map (where each idea lives)

- Entry point: `ex02/main.cpp` calls `PmergeMe::run` in `ex02/PmergeMe.cpp`.
- Input validation: `PmergeMe::parse` rejects empty tokens, non-numbers, and non-positive values.
- Vector algorithm: `PmergeMe::fordJohnsonSort` builds pairs, recurses on winners, then inserts pending values.
- Deque algorithm: `PmergeMe::fjDeq` mirrors the vector flow using `std::deque`.
- Jacobsthal scheduling: `PmergeMe::jacobsthalInsertionOrder` returns the insertion indices in block-reversed order.
- Insertion helpers: `PmergeMe::bin` (full range) and `PmergeMe::binBounded` (bounded by the paired winner).
- Timing: `PmergeMe::now` uses `gettimeofday` to produce microsecond timestamps.

---

## 3. Mental Model: Two Chains, Two Roles

- Main chain -> already sorted (safe for binary search)
- Pending chain -> losers of pair comparisons (unsorted)

This separation is the backbone of the algorithm and is represented by `mainChain` and `pendingElements` in both `PmergeMe::fordJohnsonSort` and `PmergeMe::fjDeq`.

---

## 4. Step 1 - Pairing (local, cheap, unavoidable)

Input:

```
9 3 1 7 5
```

Pair locally:

- (9,3) -> winner 9, loser 3
- (1,7) -> winner 7, loser 1
- 5 -> odd tail

These comparisons are mandatory. In code, each pair is normalized by swapping so the larger element is always stored first in `pairs`.

---

## 5. Step 2 - Recursive Sorting of Winners

Winners:

```
9 7
```

They are recursively sorted because binary search requires ordered data. This is the only recursive call in the pipeline:

- `mainChain = fordJohnsonSort(mainChain);`
- `mainChain = fjDeq(mainChain);`

---

## 6. Resulting State After Recursion

- Main chain (sorted): `[7, 9]`
- Pending chain (unsorted): `[3, 1]`
- Odd tail: `5`

Only the main chain is safe for binary search. The odd tail is appended to `pendingElements` if it exists.

---

## 7. The Real Problem

In what order should pending elements be inserted so that binary search costs the least in the worst case?

Naive insertion is suboptimal. This is where Jacobsthal numbers enter.

---

## 8. Jacobsthal Numbers (not values - schedules)

Sequence:

```
J(n) = J(n-1) + 2*J(n-2)
0, 1, 1, 3, 5, 11, 21...
```

Key realization:

- Jacobsthal does not choose values
- It chooses indices
- It defines when an insertion happens, not where

In the code, `PmergeMe::jacobsthalInsertionOrder` pushes each block in reverse, which is why the generated order looks like "reverse within checkpoints."

---

## 9. Jacobsthal = Depth Control

Binary search cost depends on depth:

```
Depth ~= log2(N) + 1
```

Jacobsthal ensures every insertion happens when its worst-case depth is already minimized. This is why the schedule in `PmergeMe::jacobsthalInsertionOrder` matters more than the raw values.

---

## 10. Why Reverse Order Inside Blocks

Example pending size = 5

Jacobsthal checkpoints:

```
1 -> 3 -> 5
```

Generated insertion order:

```
2, 1, 4, 3
```

The reverse walk inside each block avoids pushing elements deeper than necessary and keeps future insertions shallow. In code, this is the `for (i = limit; i > prev; --i)` loop in `PmergeMe::jacobsthalInsertionOrder`.

---

## 11. Binary Search: 2^n vs 2^(n+1) - 1

Crucial insight: worst-case binary search cost is identical for sizes `2^n` and `2^(n+1) - 1`.

That means we can insert without paying extra comparisons as long as we respect Jacobsthal scheduling.

---

## 12. Bounded Binary Insertion (the trick)

Instead of a full-range lower_bound:

```cpp
lower_bound(begin, end)
```

The code bounds the search by the paired winner:

```cpp
lower_bound(begin, winner_position)
```

Why it works:

- The pending element is guaranteed smaller than its paired winner
- Searching past the winner is wasted work

This is implemented in `PmergeMe::binBounded` for both `std::vector` and `std::deque`.

---

## 13. Containers: vector vs deque

Both containers run the same algorithm. The difference is cost profile:

- `std::vector` benefits from contiguous storage and cache locality
- `std::deque` favors cheaper mid-range insertions

You can see both timings in `PmergeMe::run`.

---

## 14. Final Output Contract (42-compliant)

```
Before: 4 2 3 1 5
After:  1 2 3 4 5
Time to process a range of 5 elements with std::vector : X us
Time to process a range of 5 elements with std::deque  : Y us
```

`PmergeMe::run` prints the "Before" and "After" lines plus per-container timing.

---

## 15. Diagrams 

![Comparison levels simulation](./images/COMPARISON%20LEVELS%20SIMULATION.png)
![Jacobsthal vs pending chain](./images/JACOBOSTHAL%20%3D_%20PENDINGCHAIN.png)
![Diagram 1](./images/shape_4AuWDCPreByZki2srljKe%20at%2026-01-11%2000.10.55.png)
![Diagram 2](./images/shapes%20at%2026-01-11%2000.11.17.png)
![Diagram 3](./images/shapes%20at%2026-01-11%2000.11.41.png)
![Diagram 4](./images/shapes%20at%2026-01-11%2000.12.21.png)
![Diagram 5](./images/shapes%20at%2026-01-11%2000.13.17.png)

---

## 16. What This Project Actually Taught Me

- Binary search is about decision trees, not code
- Jacobsthal is a scheduler, not a sequence gimmick
- Worst-case optimization beats average-case comfort
- Algorithms are geometry, not syntax
