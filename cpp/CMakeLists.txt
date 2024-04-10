cmake_minimum_required(VERSION 3.0)

project(ProAlgos-Cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

set(CMAKE_CXX_STANDARD 14)
if(MSVC)
        set(CMAKE_CXX_FLAGS "/W3 /EHsc /permissive- -D_USE_MATH_DEFINES")
else()
        set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wextra -pedantic-errors -fsanitize=address -fsanitize=undefined")
endif()


# Test runner
add_library(test_runner STATIC
        test/test_runner.cpp)

# ============================================================================
# Algorithms
# ============================================================================

# -------------------
# Backtracking
# -------------------

# N-queens
add_executable(n_queens
        test/algorithm/backtracking/n_queens.cpp)
target_link_libraries(n_queens test_runner)

# -------------------
# Dynamic programming
# -------------------

# Matrix chain multiplication
add_executable(matrix_chain_multiplication
        test/algorithm/dynamic_programming/matrix_chain_multiplication.cpp)
target_link_libraries(matrix_chain_multiplication test_runner)

# 0-1 knapsack
add_executable(0_1_knapsack
        test/algorithm/dynamic_programming/0_1_knapsack.cpp)
target_link_libraries(0_1_knapsack test_runner)

# Coin change
add_executable(coin_change
        test/algorithm/dynamic_programming/coin_change.cpp)
target_link_libraries(coin_change test_runner)

# Kadane's
add_executable(kadane
        test/algorithm/dynamic_programming/kadane.cpp)
target_link_libraries(kadane test_runner)

# Rod cutting
add_executable(rod_cutting
        test/algorithm/dynamic_programming/rod_cutting.cpp)
target_link_libraries(rod_cutting test_runner)

# Weighted activity selection
add_executable(weighted_activity_selection
        test/algorithm/dynamic_programming/weighted_activity_selection.cpp)
target_link_libraries(weighted_activity_selection test_runner)

# -------------
# Number theory
# -------------

# Binomial coefficient
add_executable(binomial_coefficient
        test/algorithm/number_theory/binomial_coefficient.cpp)
target_link_libraries(binomial_coefficient test_runner)

# Extended Euclidean
add_executable(extended_euclidean
        test/algorithm/number_theory/extended_euclidean.cpp)
target_link_libraries(extended_euclidean test_runner)

# Fast exponentiation
add_executable(fast_exponentiation
        test/algorithm/number_theory/fast_exponentiation.cpp)
target_link_libraries(fast_exponentiation test_runner)

# Fibonacci
add_executable(fibonacci
        test/algorithm/number_theory/fibonacci.cpp)
target_link_libraries(fibonacci test_runner)

# Fibonacci efficient
add_executable(fibonacci_efficient
        test/algorithm/number_theory/fibonacci_efficient.cpp)
target_link_libraries(fibonacci_efficient test_runner)

# Greatest common divisor
add_executable(greatest_common_divisor
        test/algorithm/number_theory/greatest_common_divisor.cpp)
target_link_libraries(greatest_common_divisor test_runner)

# Perfect number check
add_executable(perfect_number_check
        test/algorithm/number_theory/perfect_number_check.cpp)
target_link_libraries(perfect_number_check test_runner)

# Primorial
add_executable(primorial
        test/algorithm/number_theory/primorial.cpp)
target_link_libraries(primorial test_runner)

# Sieve of Eratosthenes
add_executable(sieve_of_eratosthenes
        test/algorithm/number_theory/sieve_of_eratosthenes.cpp)
target_link_libraries(sieve_of_eratosthenes test_runner)

# ---------
# Searching
# ---------

# Binary search
add_executable(binary_search
        test/algorithm/searching/binary_search.cpp)
target_link_libraries(binary_search test_runner)

# Linear search
add_executable(linear_search
        test/algorithm/searching/linear_search.cpp)
target_link_libraries(linear_search test_runner)

# Ternary search
add_executable(ternary_search
        test/algorithm/searching/ternary_search.cpp)
target_link_libraries(ternary_search test_runner)

# -------
# Sorting
# -------

# Common sorting
add_executable(sorting
        test/algorithm/sorting/sorting.cpp)
target_link_libraries(sorting test_runner)

# ------
# String
# ------

# Edit distance
add_executable(edit_distance
        test/algorithm/string/edit_distance.cpp)
target_link_libraries(edit_distance test_runner)

# Heap's
add_executable(heaps_algorithm
        test/algorithm/string/heaps_algorithm.cpp)
target_link_libraries(heaps_algorithm test_runner)

# Knuth-Morris-Pratt
add_executable(knuth_morris_pratt
        test/algorithm/string/knuth_morris_pratt.cpp)
target_link_libraries(knuth_morris_pratt test_runner)

# Longest common subsequence
add_executable(longest_common_subsequence
        test/algorithm/string/longest_common_subsequence.cpp)
target_link_libraries(longest_common_subsequence test_runner)

# Shunting yard
add_executable(shunting_yard
        test/algorithm/string/shunting_yard.cpp)
target_link_libraries(shunting_yard test_runner)

# ============================================================================
# Data structures
# ============================================================================

# -----------
# Linked list
# -----------

# Singly-linked list
add_executable(singly_linked_list
        test/data_structure/linked_list/singly_linked_list.cpp)
target_link_libraries(singly_linked_list test_runner)

# Doubly-linked list
add_executable(doubly_linked_list
        test/data_structure/linked_list/doubly_linked_list.cpp)
target_link_libraries(doubly_linked_list test_runner)

# -----
# Queue
# -----

# Queue
add_executable(queue
        test/data_structure/queue/queue.cpp)
target_link_libraries(queue test_runner)

# ---
# Set
# ---

# Disjoint set
add_executable(disjoint_set
        test/data_structure/set/disjoint_set.cpp)
target_link_libraries(disjoint_set test_runner)

# -----
# Stack
# -----

# Stack
add_executable(stack
        test/data_structure/stack/stack.cpp)
target_link_libraries(stack test_runner)

# ----
# Tree
# ----

# Binary search tree
add_executable(binary_search_tree
        test/data_structure/tree/binary_search_tree.cpp)
target_link_libraries(binary_search_tree test_runner)

add_executable(fenwick_tree
        test/data_structure/tree/fenwick_tree.cpp)
target_link_libraries(fenwick_tree test_runner)

enable_testing()

add_test(NAME 0_1_knapsack COMMAND 0_1_knapsack)
add_test(NAME binary_search COMMAND binary_search)
add_test(NAME binary_search_tree COMMAND binary_search_tree)
add_test(NAME binomial_coefficient COMMAND binomial_coefficient)
add_test(NAME coin_change COMMAND coin_change)
add_test(NAME disjoint_set COMMAND disjoint_set)
add_test(NAME doubly_linked_list COMMAND doubly_linked_list)
add_test(NAME edit_distance COMMAND edit_distance)
add_test(NAME extended_euclidean COMMAND extended_euclidean)
add_test(NAME fast_exponentiation COMMAND fast_exponentiation)
add_test(NAME fenwick_tree COMMAND fenwick_tree)
add_test(NAME fibonacci COMMAND fibonacci)
add_test(NAME fibonacci_efficient COMMAND fibonacci_efficient)
add_test(NAME greatest_common_divisor COMMAND greatest_common_divisor)
add_test(NAME heaps_algorithm COMMAND heaps_algorithm)
add_test(NAME kadane COMMAND kadane)
add_test(NAME knuth_morris_pratt COMMAND knuth_morris_pratt)
add_test(NAME linear_search COMMAND linear_search)
add_test(NAME longest_common_subsequence COMMAND longest_common_subsequence)
add_test(NAME matrix_chain_multiplication COMMAND matrix_chain_multiplication)
add_test(NAME n_queens COMMAND n_queens)
add_test(NAME perfect_number_check COMMAND perfect_number_check)
add_test(NAME primorial COMMAND primorial)
add_test(NAME queue COMMAND queue)
add_test(NAME rod_cutting COMMAND rod_cutting)
add_test(NAME shunting_yard COMMAND shunting_yard)
add_test(NAME sieve_of_eratosthenes COMMAND sieve_of_eratosthenes)
add_test(NAME singly_linked_list COMMAND singly_linked_list)
add_test(NAME sorting COMMAND sorting)
add_test(NAME stack COMMAND stack)
add_test(NAME ternary_search COMMAND ternary_search)
add_test(NAME weighted_activity_selection COMMAND weighted_activity_selection)
