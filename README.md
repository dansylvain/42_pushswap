# Push_swap Project Documentation
Because swap_push isn't as natural

## Introduction

The "push_swap" project is a sorting algorithm implementation in C, where the goal is to sort a stack of integers using a limited set of operations. This project is part of the 42 school curriculum and challenges students to develop an efficient sorting algorithm while adhering to strict performance criteria.

The project targets the development of fundamental programming skills, including data structures, algorithm design, and memory management. It also encourages students to explore advanced concepts such as dynamic programming and optimization techniques to improve the efficiency of the sorting algorithm.

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |
## Execution

### Cloning the Repository

To run the "push_swap" project, clone the repository containing the project files from GitHub:

```bash
git clone <repository_url>
```

### Compiling the Project

Navigate to the project directory and compile the project using the provided Makefile. Here's how:

```bash
cd push_swap_repo
make
```

This will compile the project and generate an executable file named push_swap. For checker, enter:
```bash
make bonus
```

### Running the Sorting Algorithm

Once compiled successfully, you can run the sorting algorithm by executing the push_swap executable with a list of integers to sort:

```bash
./push_swap 4 2 1 3
```

Replace **4 2 1 3** with the list of integers you want to sort. The algorithm will output a series of instructions to sort the stack.

### Validating the Sorting

You can validate the sorting performed by the algorithm using the **checker** executable. Pass the same list of integers to **checker**, followed by the series of instructions output by **push_swap**:

```bash
./checker 4 2 1 3 | ./push_swap 4 2 1 3
```

If the sorting is correct, checker will output **OK**. Otherwise, it will output **KO**.


## Dependencies
My implementation of the "push_swap" project includes all necessary dependencies within the source code, requiring no additional installations.

## Algorithm
I found a very inspiring article presenting the so-called "turk algorithm" and I decided to implement it using circular double linked lists, for the sake of learning new programming notions. I also added a structure to store some data.

I decided to add a pre calculation of the Longest Increasing Subsequence (LIS) in Pile_a before pushing all elements (not part of the LIS) to pile_b pre-sorting them using a pivot and dividing them in two halves.

The elements are then pushed orderly back to pile_a, each time pushing the "cheapest" one to get back. Once all elements are back, the smallest element is brought to the top of the pile with rotations.

More pre-sorting could be done using more pivots, which are already calculated, but the project targets are already hit and it is not necessary.

Calculations are all done on the stack to simplify memory management. Memory is allocated for:
- the structure
- the linked lists
- an int array
- a temporary int array in case of string input to convert it to an int array
## Evaluation Criteria
SIMPLE VERSION:
"2 1 0" > OK (2 or 3 instructions)
"1 5 2 4 3" > OK (less than 12 instructions. kudos if < 8)

MIDDLE VERSION
"100 random numbers" > OK
(< 700 -> 5)
(< 900 -> 4)
(< 1100 -> 3)
(< 1300 -> 2)
(< 1500 -> 1)

Advanced VERSION
"500 random numbers" > OK
(< 5500  -> 5)
(< 7000  -> 4)
(< 8500  -> 3)
(< 10000 -> 2)
(< 11500 -> 1)
## Resources

some links used during the project:

Links

- [the turk algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

- [random numbers generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)

- [push swap visualizer](https://github.com/o-reo/push_swap_visualizer)

- [My implementation of the 42 — push_swap project](https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f)

