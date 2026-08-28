# DS221 (Sep 2026) Assignment 1

## Total Points: 15

* **Posted on 28-08-2026**
* **Due on 26-09-2026 11:59 PM** (No extension will be granted)

## Table of Contents

| File / Folder | Description |
| --- | --- |
| [README.md](README.md) | This file — instructions, questions, and grading |
| [user_code.h](user_code.h) | **Starter file — write your solutions here** |
| [main.cpp](main.cpp) | Driver program that reads input, calls your functions, times them, and writes output (do not modify) |
| [Makefile](Makefile) | For compiling code and running test cases (do not modify) |
| [file_reader.h](file_reader.h) | Input file parsing helpers (do not modify) |
| [file_writer.h](file_writer.h) | Output file writing helpers (do not modify) |
| [sample_test/](sample_test/) | Sample input/output files for sanity-checking your solution |
| ├─ [Question_1/](sample_test/Question_1/) | Sample `input.txt` / `output.txt` for Q1 (Mess Rotation Streak) |
| ├─ [Question_2/](sample_test/Question_2/) | Sample `input.txt` / `output.txt` for Q2 (Deepest Twin Leaf Depth) |
| └─ [Question_3/](sample_test/Question_3/) | Sample `input.txt` / `output.txt` for Q3 (Automated Mailroom Robot) |
| [cluster_usage_instructions.md](cluster_usage_instructions.md) | How to log in to and use the teaching cluster |
| [cluster_schedule.md](cluster_schedule.md) | Your assigned time slot(s) on the cluster |
| [example_script.sh](example_script.sh) | Example SLURM job script template |


## INSTRUCTIONS
All problems must be solved using C++ and compile/execute correctly on the [teaching cluster](cluster_usage_instructions.md). You may test and debug on your local machine, but the final evaluation will be done on the cluster. 

All performance numbers given in your report should be on compute nodes of the cluster. Profiling experiments should be run during your assigned timeslot to avoid performance interference. TAs should be able to reproduce your performance results.

AI tools may be used for coding assistance. However, students with limited programming experience are encouraged to develop their programming skills and code without use of AI tools. If you use AI tools while developing your code, you must acknowledge their use in your report. Using AI tools is NOT allowed for preparing the report. 

Your understanding of any line in your code, your algorithms and data structures, your design choices will be tested during **oral viva conducted by the TAs**. Therefore, you are strongly encouraged to independently think and design the overall algorithm. You should critically evaluate alternative approaches on your own. Expect a few conceptual questions related to this assignment in written exams.   

You must keep your answers inaccessible to other students. Do not fork this repository because it would make your GitHub repository public by default. You are required to secure your teaching cluster account using a strong password. Please note that there will be no tolerance of academic dishonesty or negligence. 

You are provided a `main.cpp` file which calls helper functions for tasks such as file reading and writing output to a file. You are also provided a `Makefile` to compile the code. You must not change anything else in `main.cpp`. We will run our own test cases using this file, so any modifications beyond the allowed changes could affect your evaluation. You are also not allowed to change the other files used for file operations (`file_writer.h`, `file_reader.h`).

All functions you write should be added to the `user_code.h` file. You must adhere to the function signatures specified in `user_code.h`. You are allowed to add additional helper functions to `user_code.h` if necessary, as long as the main function signatures remain unchanged.

You are strongly encouraged to start the assignment early and make steady progress each week. We recommend using GitHub to maintain regular checkpoints of your work and track your code changes. While using GitHub, your repository must remain private. Periodically push your code to GitHub. Excuses like *my laptop crashed and I lost my code* will not be accepted.

In the final version of your code that you will submit, avoid printing anything to the console.

## SUBMISSION INSTRUCTIONS

Submit a zipped file `<YourIIScHandle>.zip` where you replace `<YourIIScHandle>` with the prefix of your IISc email. For example, `<YourIIScHandle>=govindsagar` if your IISc email is govindsagar@iisc.ac.in. Inside this zip file, you will have a single folder named `<YourIIScHandle>/`, and within this folder include exactly two files:  
  1. `user_code.h` – This file should contain all of your code. 
  2. `<YourIIScHandle>.pdf` – This file should include your experimental setup, observations and analysis, plots, and any other required documentation and acknowledgements.  

So the file structure should look like this:  
```
<YourIIScHandle>.zip
|--<YourIIScHandle>
   |-- user_code.h
   |-- <YourIIScHandle>.pdf
```
Any deviation from the specified file or folder names, or failure to follow the instructions for completing the assignment may result in a penalty.

-----------------------------------------------------------------------------------------------------------------------

## Report Instructions
Your report should include at least the following sections (you may add more if needed):
- Solution Approach
  - A clear explanation of the algorithm(s) used to solve the problem.
  - Include step-by-step reasoning behind the chosen method.
  - Provide diagrams or examples where helpful.
- Time and Space Complexity Analysis
  - Analyze best case, worst case, and average case scenarios.
  - Provide both theoretical analysis and practical justification.
- Experimental Setup
  - Describe the setups and different variables you choose for experiments with reasoning
- Empirical Observations
  - Report time taken and memory usage of your algorithm based on experimental runs.
  - Present results in tabular or graphical format for clarity.
  - Compare empirical results with theoretical expectations.
  - Discuss scalability (how the algorithm performs as input size increases).
  - Detailed Analysis with Different Algorithmic Approaches if more than one tried
    - Provide time and space complexity for each approach.
    - Justify why you chose the final implementation over the alternatives.
- Additional Insights (Optional but Recommended)
  - For example: Mention possible optimizations and trade-offs.

-----------------------------------------------------------------------------------------------------------------------

## QUESTIONS
-----------------------------------------------------------------------------------------------------------------------

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

#### Grading  
- 2 marks for profiling and report  
- 2 marks for code and viva  


-----------------------------------------------------------------------------------------------------------------------


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

### Hints

Hint 1: How do you tell "same multiset" quickly?
When you walk from the root down to a leaf, you get a list of numbers (the path). To check if two paths are anagrams of each other, you don't need to compare them directly — you can just **sort each path** and compare the sorted versions. (If two sorted paths are equal, the original paths must have the same numbers, just possibly in a different order.)

Hint 2: Group leaves so you're not comparing everyone to everyone.
Instead of comparing every pair of leaves in the whole tree, put each leaf into a "bucket" based on its `(depth, sorted path)`. Any two leaves in the *same* bucket automatically have the same multiset.

Hint 3: Inside one bucket, how do you check "different order"?
Within a bucket, look at the **original (unsorted) paths**. If two leaves in the same bucket have the *exact same* original path, they're just duplicates of each other — not twins.

#### Grading  
- 2 marks for profiling and report  
- 2 marks for code and viva  



-----------------------------------------------------------------------------------------------------------------


## Question 3: Automated Mailroom Robot

### Problem Description

You are programming the navigation and delivery logic for an automated mailroom robot in a large corporate office. 

Packages arrive from a basement warehouse via a conveyor belt into the Arrival Room. The robot has a vertical carrying bin that operates strictly as a **Stack** (Last-In, First-Out). Because the bin is narrow, the robot can only deliver a package if it is currently sitting at the absolute top of the stack.

The robot must pick up packages from the conveyor belt (which acts as a **Queue**—First-In, First-Out), load them into its stack, and navigate the office to deliver them. If a package needs to be delivered but is trapped beneath other packages, the robot cannot deliver it. It has two choices:

1. Travel to the top package's destination and deliver that one first (even if it's further away).
2. Travel to a designated **Sorting Room**. In a Sorting Room, the robot can temporarily unload its stack onto a table and reload the packages in any order it chooses.

Your task is to write an algorithm that calculates the **minimum total time** required for the robot to load and deliver all packages. *(Assume the graph to be connected).*

**The Rules & Mechanics:**
* **The Building:** The office is an undirected graph of rooms (nodes) connected by hallways (edges). Each hallway has a travel time (weight). *(Assume the graph to be connected).*
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

### Constraints

* $2 \le N \le 500$
* $2 \le E \le 2000$
* $1 \le C \le 10$
* $0 \le S, w \le 1000$

### Hints

Hint 1: Calculating all-pair shortest paths may be useful, if you look at the small number of packages, you might realize you only need the distances between a few key rooms.

Hint 2: Think about how the stack (LIFO) naturally reverses your default delivery order. Also, ask yourself if going to the sorting room a second time would ever actually help.

Hint 3: Since there are at most 10 packages (C <= 10), consider if the number of possible delivery combinations after a sort is small enough that you can just try all of them.

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
```

#### Grading  
- 3 marks for profiling and report  
- 4 mark for code and viva  

## Need help? 
If you have any question, you can raise them during the weekly tutorial sessions with the TAs. You can also raise your question on DS221 Teams- `Doubts` channel.
