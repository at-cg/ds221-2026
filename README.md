## Question 1: Task Scheduler with Per-Task Cooldowns

You're given distinct task types, how many times each occurs, and a different cooldown for each type. A task type can only run again after its own cooldown has fully elapsed. Find the **minimum total time units** (including forced idle slots) to finish all tasks.

Formally: if a task of type `i` runs at time `t`, it cannot run again until time `t + cooldown[i] + 1`.

**Input:** Three parallel arrays — `tasks[i]` is a type label, `counts[i]` its occurrence count, `cooldown[i]` its cooldown.

**Output:** Single integer — minimum total time units.

### Constraints

- `1 <= len(tasks) <= 26`
- `1 <= counts[i] <= 10^4`
- `0 <= cooldown[i] <= 100`

### Sample Test Cases

**Sample 1**
```
Input:  tasks=["A","B"], counts=[2,2], cooldown=[2,2]
Output: 5
```
Explanation: The tasks are performed in the order `A B idle A B`.

**Sample 2**
```
Input:  tasks=["A","B","C"], counts=[3,1,1], cooldown=[1,0,0]
Output: 5
```
Explanation: No idle needed — B and C (cooldown 0) slot neatly between A's repeats. An optimal order is: `A B A C A`

---

## Question 2: Deepest Twin Leaf Depth

### Definitions

For any leaf, its **path sequence** = the list of values from root down to that leaf, in order.

Two leaves at the **same depth** are **Twins** if:
1. Their path sequences are **anagrams** of each other (same multiset of values), **and**
2. Their path sequences are **not identical** — they must differ in order at some position.

*(A leaf pair with the exact same sequence, same order, is not a twin pair — they're just duplicates)*

### Problem Description

Return the **maximum depth** (root = depth 0) at which any twin pair exists. Return `-1` if no twin pair exists anywhere in the tree.


**Input :** `root` — level-order array with `null` for missing children.

**Output:** Single integer — max depth with a twin pair, or `-1`.

### Constraints

- `1 <= nodes <= 10^4`
- `-10^4 <= Node.val <= 10^4`
- height `<= 1000`

### Sample Test Cases

**Sample 1**
```
Input:  root = [1,2,3,3,null,null,2]
Output: 2
```
Explanation: Leaves: `root.left.left=3` → path `[1,2,3]`, depth 2. `root.right.right=2` → path `[1,3,2]`, depth 2. Same multiset `{1,2,3}`, different order → twins → **2**.

**Sample 2**
```
Input:  root = [5,5,6]
Output: -1
```
Explanation: Leaves: `[5,5]` (depth 1) and `[5,6]` (depth 1). Multisets `{5,5}` vs `{5,6}` — don't even match → **-1**.

**Sample 3** (twins exist at two depths — must pick the deeper one)
```
Input:  root = [1,2,3,3,3,2,2,7,null,null,null,null,null,null,7]
Output: 3
```
Explanation: Leaves: `[1,2,3]` & `[1,3,2]` (depth 2, twins) and `[1,2,3,7]` & `[1,3,2,7]` (depth 3, twins — multiset `{1,2,3,7}` both, order differs). Both depths qualify → return the deeper one, **3**.

Note: If there is, say, only one leaf at the deepest level, but valid pair one level shallower, you must not return `-1` just because the deepest level has an unpaired leaf.
