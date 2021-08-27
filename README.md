# ProAlgos: C++

[![Travis status][travis-shield]][travis-link]

This project is focused on implementing **algorithms and data structures** in C++, while following **good software engineering practices**, such as: 

- Writing well-documented code
- Adhering to code guidelines
- Writing and passing unit tests
- Reviewing each other's code

## Goals

1. Implement algorithms and data structures
1. Learn to be better software developers
1. Guide one another on version control, unit testing, and algorithms

## How to get involved

There are a few ways to get involved.

#### Want to contribute to open-source and get involved with the project?

1. **Read** the [contribution guidelines][contrib-guide]
1. **Fork** the repo
1. **Create an issue** describing what you'd like to add, or **claim an issue** that's [up for grabs][up-for-grabs]
1. Create a **branch** and **add your code**
1. Submit a **pull request** and reference the issue it closes

You can find more details regarding the steps above in the [contribution
guidelines][contrib-guide], so be sure to check them out.

#### Just want to suggest a new algorithm or report a bug?

[Create a new issue](https://github.com/ProAlgos/ProAlgos-Cpp/issues/new) and we'll
handle it from there. :smile:

## Contents

:white_check_mark: = has unit tests

### Algorithms

* Backtracking
  * [N-Queens](cpp/include/algorithm/backtracking/n_queens.hpp) :white_check_mark:

* Dynamic programming
  * [0-1 knapsack](cpp/include/algorithm/dynamic_programming/0_1_knapsack.hpp) :white_check_mark:
  * [Coin change](cpp/include/algorithm/dynamic_programming/coin_change.hpp) :white_check_mark:
  * [Longest decreasing subsequence](cpp/include/algorithm/dynamic_programming/longest_decreasing_subsequence.hpp) :white_check_mark:
  * [Matrix chain multiplication](cpp/include/algorithm/dynamic_programming/matrix_chain_multiplication.hpp) :white_check_mark:
  * Maximum sum contiguous subarray: [Kadane's algorithm](cpp/include/algorithm/dynamic_programming/kadane.hpp) :white_check_mark:
  * [Rod cutting](cpp/include/algorithm/dynamic_programming/rod_cutting.hpp) :white_check_mark:
  * [Weighted activity selection](cpp/include/algorithm/dynamic_programming/weighted_activity_selection.hpp) :white_check_mark:

* Number theory
  * [Binomial coefficient](cpp/include/algorithm/number_theory/binomial_coefficient.hpp) :white_check_mark:
  * Euclidean algorithms
    * [Greatest common divisor](cpp/include/algorithm/number_theory/greatest_common_divisor.hpp) (GCD) :white_check_mark:
    * [Extended Euclidean algorithm](cpp/include/algorithm/number_theory/extended_euclidean.hpp) (Bézout coefficients) :white_check_mark:
  * [Fast exponentiation](cpp/include/algorithm/number_theory/fast_exponentiation.hpp) :white_check_mark:
  * Nth Fibonacci number
    * [Linear time algorithm](cpp/include/algorithm/number_theory/fibonacci.hpp) :white_check_mark:
    * [Logarithmic time algorithm](cpp/include/algorithm/number_theory/fibonacci_efficient.hpp) :white_check_mark:
  * [Perfect number check](cpp/include/algorithm/number_theory/perfect_number_check.hpp) :white_check_mark:
  * Prime numbers
    * [Primorial](include/algorithm/number_theory/primorial.hpp) :white_check_mark:
    * [Sieve of Eratosthenes (simple)](cpp/include/algorithm/number_theory/sieve_of_eratosthenes.hpp) :white_check_mark:
  
* Searching
  * [Binary search](cpp/include/algorithm/searching/binary_search.hpp) :white_check_mark:
  * [Linear search](cpp/include/algorithm/searching/linear_search.hpp) :white_check_mark:
  * [Ternary search](cpp/include/algorithm/searching/ternary_search.hpp) :white_check_mark:
  
* Sorting
  * [Bubble sort](cpp/include/algorithm/sorting/bubble_sort.hpp) :white_check_mark:
  * [Bucket sort](cpp/include/algorithm/sorting/bucket_sort.hpp) :white_check_mark:
  * [Comb sort](cpp/include/algorithm/sorting/comb_sort.hpp) :white_check_mark:
  * [Counting sort (stable)](cpp/include/algorithm/sorting/counting_sort.hpp) :white_check_mark:
  * [Heap sort](cpp/include/algorithm/sorting/heap_sort.hpp) :white_check_mark:
  * [Insertion sort](cpp/include/algorithm/sorting/insertion_sort.hpp) :white_check_mark:
  * [Merge sort](cpp/include/algorithm/sorting/merge_sort.hpp) :white_check_mark:
  * [Quick sort](cpp/include/algorithm/sorting/quick_sort.hpp) :white_check_mark:
  * [Radix sort](cpp/include/algorithm/sorting/radix_sort.hpp)
  * [Selection sort](cpp/include/algorithm/sorting/selection_sort.hpp) :white_check_mark:
  * [Shell sort](cpp/include/algorithm/sorting/shell_sort.hpp) :white_check_mark:

* String
  * [Longest common subsequence](cpp/include/algorithm/string/longest_common_subsequence.hpp) :white_check_mark:
  * Searching (pattern matching)
    * [Knuth-Morris-Pratt](cpp/include/algorithm/string/knuth_morris_pratt.hpp) :white_check_mark:
  * [Edit Distance Problem](cpp/include/algorithm/string/edit_distance.hpp) :white_check_mark:
  * [Shunting yard](cpp/include/algorithm/string/shunting_yard.hpp) :white_check_mark:
  * Permutation
    * [Heap's Algorithm](cpp/include/algorithm/string/heaps_algorithm.hpp) :white_check_mark:

### Data structures

* Linked List
  * [Singly linked list](cpp/include/data_structure/linked_list/singly_linked_list.hpp) :white_check_mark:
  * [Doubly linked list](cpp/include/data_structure/linked_list/doubly_linked_list.hpp) :white_check_mark:
  
* Queue
  * [Queue](cpp/include/data_structure/queue/queue.hpp) :white_check_mark:
  
* Set
  * [Disjoint-set](cpp/include/data_structure/set/disjoint_set.hpp) :white_check_mark:
  
* Stack
  * [Stack](cpp/include/data_structure/stack/stack.hpp) :white_check_mark:
  
* Tree
  * [Binary search tree](cpp/include/data_structure/tree/binary_search_tree.hpp) :white_check_mark:
  * [Fenwick tree](cpp/include/data_structure/tree/fenwick_tree.hpp) :white_check_mark:
  * [Segment Tree](cpp/include/data_structure/tree/segment_tree.hpp) :white_check_mark:

## Compiling

To compile the source files, run **`make`** from the `C++` directory. Doing so will create executable binaries in the `bin` directory.

To compile and run all tests, run **`make test`**. This will compile all the tests (in the same way as described above) and will run them, displaying the results. 

In order to run a specific test and see its results, run it manually from the `bin` directory after calling `make`. For example, this command (executed from `bin`) would run only the unit tests for the N Queens algorithm:

```
$ ./n_queens
```

To remove all of the files created during compilation, run **`make clean`**. You need not do this every time you make some changes to a file and want to recompile it. Just run **`make`** and it will re-compile just those files whose contents have changed.

To see what happens in the background during compilation and testing, see the following files:

- [Makefile](cpp/Makefile)
- [CMakeLists.txt](cpp/CMakeLists.txt)
- [Testing script](cpp/scripts/run_tests.sh)

For more information on `make`, see the [GNU make Manual](https://www.gnu.org/software/make/manual/make.html). For more information on `CMake`, see the [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html).

## Maintainers

This project is actively maintained by [@alxmjo](https://github.com/alxmjo), and inactively by [@faheel](https://github.com/faheel).

## License

This project is licensed under the terms of the [MIT license](LICENSE.md).

[travis-shield]: https://img.shields.io/travis/ProAlgos/ProAlgos-Cpp.svg?style=for-the-badge
[travis-link]: https://travis-ci.org/ProAlgos/ProAlgos-Cpp
[contrib-guide]: docs/CONTRIBUTING.md
[up-for-grabs]: https://github.com/ProAlgos/ProAlgos-Cpp/labels/Up%20for%20grabs
