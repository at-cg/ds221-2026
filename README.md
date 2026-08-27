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

## Question 3: Automated Mailroom Robot

### Problem Description

You are programming the navigation and delivery logic for an automated mailroom robot in a large corporate office. 

Packages arrive from a basement warehouse via a conveyor belt into the Arrival Room. The robot has a vertical carrying bin that operates strictly as a **Stack** (Last-In, First-Out). Because the bin is narrow, the robot can only deliver a package if it is currently sitting at the absolute top of the stack.

The robot must pick up packages from the conveyor belt (which acts as a **Queue**—First-In, First-Out), load them into its stack, and navigate the office to deliver them. If a package needs to be delivered but is trapped beneath other packages, the robot cannot deliver it. It has two choices:

1. Travel to the top package's destination and deliver that one first (even if it's further away).
2. Travel to a designated **Sorting Room**. In a Sorting Room, the robot can temporarily unload its stack onto a table and reload the packages in any order it chooses.

Your task is to write an algorithm that calculates the **minimum total time** required for the robot to load and deliver all packages. *(Assume the graph to be connected).*

**The Rules & Mechanics:**
* **The Building:** The office is an undirected graph of rooms (nodes) connected by hallways (edges). Each hallway has a travel time (weight).
* **The Arrival Room:** Node `0` is always the Arrival Room. The robot loads packages and starts delivery from here.
* **Loading:** Loading takes `1` unit of time per package. The first package loaded from the queue goes to the bottom of the stack; the last package loaded stays on top.
* **Delivering:** Delivering takes `0` units of time after reaching the room. The robot can only drop off a package if it is in the correct room (i.e. the room for which the current package is designated) AND that package is currently at the top of the stack.
* **Sorting:** Navigating to the Sorting Room and rearranging the stack takes a fixed time penalty of `S` units of time, regardless of how many packages are in the stack.
* **Completion:** The task is complete when all packages in the bin have been delivered.

### Input Format
Read from a standard text file with the following structure:
* **Line 1:** Four integers `N E C S` (Total rooms, Number of hallways, Number of packages to be delivered, Sorting time penalty).
* **Next E lines:** Three integers `u v w` representing a hallway between room `u` and room `v` with a travel time of `w`.
* **Next Line:** An integer `K` representing the ID of the Sorting Room.
* **Next Line:** `C` integers representing the destination room IDs for the packages, in the exact order they sit on the conveyor belt i.e. first package on conveyer belt is the first element on queue. *(Assume all packages fit in the bin at once and there is atmost one package for each room).*

### Output Format
* **Minimum Total Time:** A single integer representing the fastest possible time to load and complete all deliveries.

### Deliverables to Report
Along with your source code, you must submit a brief technical report containing:
* **Empirical Runtime:** Execution time analysis by varying the graph size.
* **Theoretical Analysis:** Time and space complexity in Big-O notation.
* **Optimization:** Is it possible to achieve an asymptotically faster runtime? If no, explain why. If yes, explain or implement the optimal approach.

### Constraints

* $2 \le N \le 500$
* $2 \le E \le 2000$
* $1 \le C \le 10$
* $0 \le S, w \le 1000$

### Sample Test Cases

**Sample 1**
```text
Input:
4 3 3 2
0 1 10
0 2 10
1 3 10
0
1 2 3

Output:
45

Explaination:
Loading 3 packages takes: 3
Sorting on node 0 takes: 2 [sorted as: 2,1,3 (top to bottom on stack)]
Delivery takes: 10 + 20 + 10 = 40
Total time: 45

