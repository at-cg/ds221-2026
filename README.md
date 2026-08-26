## Question 1: Mess Rotation Streak

The 5 IISc messes — A, B, C, D, E — follow a fixed weekly special-dish rotation: A → B → C → D → E → A → B → ..., repeating cyclically forever (day `n` continues right where day `0` left off — the schedule never resets). Every day, students report a satisfaction delta for that day's special dish: positive if they liked it more than the regular menu, negative if less. Find the maximum sum achievable over any contiguous streak of days, where a streak is allowed to wrap around from the end of the log back to the beginning, since the rotation itself doesn't stop where your log happens to end.

Formally: given an array `delta[n]`, find `max(delta[i] + delta[i+1] + ... + delta[j])` over all valid streaks, where a streak may either be a normal contiguous range `[i, j]` (`i <= j`), or a wrapping range covering `[i, n-1] + [0, j]` (`j < i`). A streak must be non-empty, and cannot span the entire array wrapped all the way around (i.e., it cannot include every element twice).

**Input:** Single array — `delta[i]` is the satisfaction delta for day `i`.

**Output:** Single integer — maximum streak sum.

### Constraints

- `1 <= n <= 10^5`
- `-10^4 <= delta[i] <= 10^4`

### Sample Test Cases

**Sample 1**
```
Input: delta=[3,-1,2,-5,4]
Output: 8
```
Explanation: Wrapping the streak — day E (`4`) followed by days A, B, C (`3, -1, 2`) — gives `4+3-1+2 = 8`

**Sample 2**
```
Input: delta=[-2,-3,-1,-4]
Output: -1
```
Explanation: The best streak is just the single least-negative day, `[-1]`, giving `-1`.

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

## Question 3: Disaster Relief Convoy

### Problem Description

A relief convoy must travel from `source` to `destination` through a road network of `n` nodes (0-indexed, undirected, possibly with parallel edges).

Each road belongs to one of two kinds:
- **Free road** — no restriction, use as many times as needed.
- **Restricted road** — belongs to one of several **hazard categories** (e.g. `"bridge"`, `"tunnel"`). Crossing a restricted road of category `c` consumes one unit from that category's **engineering escort budget**. Each category has its own separate budget — using up the `"bridge"` budget does not affect the `"tunnel"` budget, and budgets are **not interchangeable**.

Find the **minimum total cost** route from `source` to `destination` such that, for every hazard category, the number of restricted roads of that category used does **not exceed its budget**. A route may revisit nodes/edges if useful; budgets are consumed cumulatively over the whole route, not per visit.

**Input:**
- `n` — number of nodes
- `edges` — list of `[u, v, cost, category]`, where `category` is `0` for a free road, or an index `i >= 1` meaning it belongs to `categories[i-1]`
- `categories` — list of distinct hazard category names
- `budget` — parallel array; `budget[i]` is the max number of `categories[i]` roads usable in the route
- `source`, `destination`

**Output:** Single integer — minimum total cost, or `-1` if no route satisfies both reachability *and* every category budget.

### Constraints

- `1 <= n <= 100`
- `0 <= edges.length <= 500`
- `0 <= cost <= 1000`
- `0 <= len(categories) <= 3`
- `0 <= budget[i] <= 10`
- `0 <= source, destination < n`

### Sample Test Cases

Samples 1–3 share this graph:

```
n = 5
categories = ["bridge", "tunnel"]
edges = [
  [0, 1, 10, 0],        // free, cost 10
  [1, 4, 10, 0],        // free, cost 10
  [0, 2, 2, 1],         // bridge, cost 2
  [2, 4, 2, 1],         // bridge, cost 2
  [0, 3, 3, 2],         // tunnel, cost 3
  [3, 4, 1, 1]          // bridge, cost 1
]
source = 0, destination = 4
```

**Sample 1**
```
Input:  budget = [1, 1]
Output: 4
```
Explanation: Route `0→3 (tunnel, 3)→4 (bridge, 1)` costs `4`, using 1 tunnel and 1 bridge — within budget, and cheaper than the free-only route (`20`) or the double-bridge route `0→2→4` (which needs 2 bridges, over budget).

**Sample 2 (the trap)**
```
Input:  budget = [1, 0]
Output: 20
```
Explanation: You'd think having 1 bridge left is useful, but every way to *reach* a bridge edge from `0` (nodes 2 or 3) requires either 2 bridges (`0→2→4`, over the bridge budget) or 1 tunnel (`0→3→4`, and the tunnel budget is `0`). Neither works, so the bridge budget goes unused and you fall back to the all-free route `0→1→4 = 20`. Budget for one category is worthless if reaching it costs a category you don't have budget for.

**Sample 3**
```
Input:  budget = [0, 0]
Output: 20
```
Explanation: No restricted roads allowed at all — only the free route `0→1→4` works, cost `20`.

**Sample 4 (reachable but infeasible)**
```
Input:  n = 3
        categories = ["tunnel"]
        edges = [[0, 1, 1, 1], [1, 2, 1, 1]]
        budget = [1]
        source = 0, destination = 2
Output: -1
```
Explanation: `0` and `2` are perfectly connected in the graph, but the *only* route between them (`0→1→2`) crosses two tunnel edges, and the tunnel budget is only `1`. Plain reachability is not enough — this is the core trick of the problem: a route can exist structurally and still be impossible under the budget.
