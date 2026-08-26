## Question 1: Mess Rotation Streak

The 5 IISc messes — A, B, C, D, E — follow a fixed weekly special-dish rotation: A → B → C → D → E → A → B → ..., repeating every 5 days for the whole semester. Every day, students report a satisfaction delta for that day's special dish: positive if they liked it more than the regular menu, negative if less. Find the maximum sum achievable over any contiguous streak of days (a "streak" means consecutive days, no skipping).

Formally: given an array `delta[n]`, find `max(delta[i] + delta[i+1] + ... + delta[j])` over all valid ranges `0 <= i <= j <= n-1`. A streak must be non-empty (you must pick at least one day).

**Input:** Single array — `delta[i]` is the satisfaction delta for day `i`.

**Output:** Single integer — maximum streak sum.

### Constraints

- `1 <= n <= 10^5`
- `-10^4 <= delta[i] <= 10^4`

### Sample Test Cases

**Sample 1**
```
Input: delta=[3,-1,2,-5,4]
Output: 4
```
Explanation: The best streak is days A, B, C — `[3, -1, 2]` — summing to `4`. Extending further to include day D (`-5`) or starting fresh at day E (`4`, sum `4`, tied but not better) doesn't beat it.

**Sample 2**
```
Input: delta=[-2,-3,-1,-4]
Output: -1
```
Explanation: The best streak is just the single least-negative day, `[-1]`, giving `-1`.

---

## Question 2: Deepest Twin Leaf Depth

Consider a binary tree where each node holds an integer value. For any leaf in the tree, define its **path sequence** as the list of values encountered from the root down to that leaf, in order.

Two leaves at the *same depth* are called **Twins** if:

1. Their path sequences are anagrams of each other (i.e., the same multiset of values), and
2. Their path sequences are not identical — they must differ in order at some position.

Your task is to find the **maximum depth** (root = depth 0) at which at least one twin pair exists anywhere in the tree.

**Input:** `root` — a level-order array representation of the tree, with `null` for missing children.

**Output:** Single integer — the maximum depth at which a twin pair exists, or `-1` if no twin pair exists anywhere in the tree.

**Constraints**

* `1 <= nodes <= 10^4`
* `-10^4 <= Node.val <= 10^4`
* `height <= 1000`

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

Hints:

Hint 1 — How do you tell "same multiset" quickly?
When you walk from the root down to a leaf, you get a list of numbers (the path). To check if two paths are anagrams of each other, you don't need to compare them directly — you can just **sort each path** and compare the sorted versions. (If two sorted paths are equal, the original paths must have the same numbers, just possibly in a different order.)

Hint 2 — Group leaves so you're not comparing everyone to everyone.
Instead of comparing every pair of leaves in the whole tree, put each leaf into a "bucket" based on its `(depth, sorted path)`. Any two leaves in the *same* bucket automatically have the same multiset.

Hint 3 — Inside one bucket, how do you check "different order"?
Within a bucket, look at the **original (unsorted) paths**. If two leaves in the same bucket have the *exact same* original path, they're just duplicates of each other — not twins.

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
