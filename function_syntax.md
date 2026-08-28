## **Function:** `question_one`

---

Given an array of daily satisfaction deltas $\texttt{delta}$, this function finds the
maximum sum achievable over any **contiguous, non-empty** streak (subarray) of
$\texttt{delta}$.

$\textbf{Input:}$
- $\texttt{delta}$ : vector of integers where
  - $\texttt{delta[i]}=$ satisfaction delta reported for day $i$

$\textbf{Input constraints:}$
- $1 \leq n \leq 10^{5}$, where $n$ is the number of days
- $-10^{4} \leq \texttt{delta[i]} \leq 10^{4}$

$\textbf{Output:}$
- A single integer: the maximum sum over all contiguous, non-empty subarrays of
  $\texttt{delta}$. (You must pick at least one day.)

**Function Signature:**

```cpp
long long question_one(const vector<int>& delta);
```

<br><br>

## **Function:** `question_two`

---

Given a binary tree in level-order array form, this function finds the maximum
depth (root = depth $0$) at which two **leaves** exist whose root-to-leaf path
sequences are anagrams of each other (same multiset of values) but are **not**
identical in order — a **twin pair**. If no twin pair exists at any depth, the
function returns $-1$.

$\textbf{Input:}$
- $\texttt{root}$ : vector of integers representing the standard level-order
  (BFS) serialization of the binary tree
  - A missing child (`null`) is represented by the sentinel value NULL_NODE = -100000, which lies outside the valid node-value range $[-10^{4}, 10^{4}]$, so it can never be confused with a real value
  - Follows the usual convention: a missing node does **not** contribute
    placeholder entries for its own children in the listing (e.g.
    `[1, 2, 3, 3, NULL_NODE, NULL_NODE, 2]` means node `1` has children `2, 3`;
    node `2` (index 1) has no children listed; node `3` (index 2) has children
    `NULL_NODE, 2`)

$\textbf{Input constraints:}$
- $1 \leq \texttt{nodes} \leq 10^{4}$, where $\texttt{nodes}$ is the number of
  non-null nodes
- $-10^{4} \leq \texttt{Node.val} \leq 10^{4}$
- $\texttt{height} \leq 1000$

$\textbf{Output:}$
- A single integer: the maximum depth at which a twin pair exists anywhere in
  the tree, or $-1$ if none exists.

**Function Signature:**

```cpp
const int NULL_NODE = -100000;  // sentinel value denoting a missing child

int question_two(const vector<int>& root);
```

*Note: `NULL_NODE` is provided as a constant so every entry of `root` is a
plain `int`, and any entry equal to `NULL_NODE` should be treated as a missing
node. You are free to first reconstruct an explicit tree structure (e.g. with
a `TreeNode` struct) from `root` inside `user_code.h` before running your
algorithm.*

<br><br>

## **Function:** `question_three`

---

The office building is modeled as a weighted, undirected, connected graph of
rooms. A mailroom robot starts at the Arrival Room (node $0$), loads packages
from a queue onto a LIFO stack, and must deliver every package, optionally
visiting a designated Sorting Room to unload and reload its stack in any order
(each visit costs a fixed penalty $S$, regardless of stack size). This function
computes the minimum total time (loading + travel + sorting) to deliver all
packages.

$\textbf{Input:}$
- $\texttt{N}$ : total number of rooms (nodes), numbered $0$ to $\texttt{N}-1$;
  node $0$ is always the Arrival Room
- $\texttt{S}$ : fixed time penalty for one visit to the Sorting Room,
  regardless of how many packages are rearranged
- $\texttt{sortingRoom}$ : the room ID ($\texttt{K}$) of the designated Sorting
  Room
- $\texttt{edges}$ : vector of vectors where
  - $\texttt{edges[i][0]}, \texttt{edges[i][1]}=$ the two rooms connected by
    hallway $i$
  - $\texttt{edges[i][2]}=$ travel time of hallway $i$
- $\texttt{packageDestinations}$ : vector of destination room IDs, in the exact
  order the packages sit on the conveyor belt (i.e. the order they are loaded,
  first element loaded first — and thus ends up at the **bottom** of the
  stack)

$\textbf{Input constraints:}$
- $2 \leq \texttt{N} \leq 500$
- $2 \leq \texttt{E} \leq 2000$, where $\texttt{E} = \texttt{edges.size()}$ is
  the number of hallways
- $1 \leq \texttt{C} \leq 10$, where
  $\texttt{C} = \texttt{packageDestinations.size()}$ is the number of packages
- $0 \leq \texttt{S}, w \leq 1000$, where $w$ is any hallway's travel time
- The graph is guaranteed to be connected
- At most one package per destination room

$\textbf{Output:}$
- A single integer: the minimum total time (loading + delivering + sorting) to
  deliver every package.

**Function Signature:**

```cpp
long long question_three(
    int N,
    int S,
    int sortingRoom,
    const vector<vector<int>>& edges,
    const vector<int>& packageDestinations
);
```
