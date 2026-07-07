# Plan: Implement Insertion Sort for push_swap

## Goal
Create an O(n²) insertion sort for `sort_simple` that handles low-disorder inputs efficiently (under 700 ops for n=100, under 5500 for n=500).

## Algorithm: Insertion Sort with Stack B as Buffer

### Phase 1: Push all elements to B
- Push everything from A to B (n `pb` operations)
- Stack B now has all elements, A is empty

### Phase 2: Insert elements back into A in sorted order
- For each element in B (from top to bottom):
  1. Find its correct insert position in A (where it should go to keep A sorted)
  2. Rotate A to bring that position to the top
  3. Push the element from B to A (`pa`)
- Repeat until B is empty

### Phase 3: Final rotation to bring min to top
- Rotate A so the smallest element is at top

## Why this works for low disorder

For nearly-sorted arrays:
- Each element is already close to its final position
- Finding insert position is fast (binary search or linear scan)
- Rotations are minimal (element is near its correct spot)
- Total ops: ~n pushes + ~n insertions with few rotations each

For worst-case (fully reversed):
- Still O(n²) — each element may need ~n rotations
- But that's the theoretical bound, and we only use this for low disorder

## Implementation Steps

1. **Create `sort_insertion.c`** with:
   - `find_insert_pos()` — find where value fits in sorted A
   - `rotate_to_pos()` — rotate A to bring position to top
   - `sort_insertion()` — main algorithm

2. **Update `push_swap.h`** — add `sort_insertion()` declaration

3. **Update `sort_adaptive.c`** — use `sort_insertion` for low disorder instead of `sort_simple`

4. **Keep `sort_simple.c`** — for n ≤ 5 hardcoded optimal moves

5. **Test** with e2e_test.sh

## Files to modify

| File | Change |
|------|--------|
| `sorting_prog/sort_insertion.c` | New file |
| `push_swap.h` | Add `void sort_insertion(t_prog_state *state);` |
| `sorting_prog/sort_adaptive.c` | `disorder < 0.2` → `sort_insertion(state)` |
| `Makefile` | Add `sort_insertion.c` to SRCS |

## Complexity analysis

- **Time**: O(n²) in worst case, O(n) for nearly-sorted
- **Space**: O(1) extra (uses stack B)
- **Operations**: For low disorder, ~2n + small rotations per element

## Expected results

| Size | Disorder | Expected ops | Limit |
|------|----------|-------------|-------|
| 100 | < 0.2 | ~300-500 | 700 |
| 500 | < 0.2 | ~1500-2500 | 5500 |

## Notes

- `find_insert_pos` can use linear scan (O(n) per element = O(n²) total)
- For push_swap, we need the position in the circular stack, not array index
- Must handle circular rotation correctly (min element may be anywhere)
