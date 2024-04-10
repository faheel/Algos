#include <random>
#include <limits>
#include "third_party/catch.hpp"
#include "algorithm/sorting/bubble_sort.hpp"
#include "algorithm/sorting/bucket_sort.hpp"
#include "algorithm/sorting/comb_sort.hpp"
#include "algorithm/sorting/counting_sort.hpp"
#include "algorithm/sorting/heap_sort.hpp"
#include "algorithm/sorting/insertion_sort.hpp"
#include "algorithm/sorting/merge_sort.hpp"
#include "algorithm/sorting/quick_sort.hpp"
#include "algorithm/sorting/radix_sort.hpp"
#include "algorithm/sorting/selection_sort.hpp"
#include "algorithm/sorting/shell_sort.hpp"

// Prototypes
int generate_random_int(int, int);
vector<int> generate_unsorted_vector(const bool is_unsigned = false, int max_size = 1000);

// Pointer to function
using sorting_function = void(*)(vector<int>&, int, bool);

// Constant value
const int TIMES_TO_RUN = 20;

TEST_CASE("Sort in ascending order", "[sorting]") {
    // Sorting algorithms
    vector<sorting_function> sorting_functions = {
        bubble_sort,
        bucket_sort,
        comb_sort,
        counting_sort,
        heap_sort,
        insertion_sort,
        merge_sort,
        quick_sort,
        // radix_sort,      // This test reveals that the radix sort is broken
        selection_sort,
        shell_sort
    };

    vector<int> original, algo_sorted, std_sorted;

    int times_to_run = TIMES_TO_RUN;
    while (times_to_run--) {
        original = algo_sorted = std_sorted = generate_unsorted_vector();
        std::sort(std_sorted.begin(), std_sorted.end());

        // Run tests
        for (auto sorting_algo : sorting_functions) {
            sorting_algo(algo_sorted, 1, false);
            REQUIRE(algo_sorted == std_sorted);
            algo_sorted = original;
        }

        // radix sort special case, since curr impl supports only unsigned
        original = algo_sorted = std_sorted = generate_unsorted_vector(true);
        std::sort(std_sorted.begin(), std_sorted.end());

        // Run tests
        radix_sort(algo_sorted, 1, false);
        REQUIRE(algo_sorted == std_sorted);
    }
}

TEST_CASE("Sort in descending order", "[sorting]") {
    // Sorting algorithms
    vector<sorting_function> sorting_functions = {
        bubble_sort,
        bucket_sort,
        comb_sort,
        counting_sort,
        heap_sort,
        insertion_sort,
        merge_sort,
        quick_sort,
        // radix_sort,      // This test reveals that the radix sort is broken
        selection_sort,
        shell_sort
    };

    vector<int> original, algo_sorted, std_sorted;

    int times_to_run = TIMES_TO_RUN;
    while (times_to_run--) {
        original = algo_sorted = std_sorted = generate_unsorted_vector();
        std::sort(std_sorted.rbegin(), std_sorted.rend());

        // Run tests
        for (auto sorting_algo : sorting_functions) {
            sorting_algo(algo_sorted, -1, false);
            REQUIRE(algo_sorted == std_sorted);
            algo_sorted = original;
        }

        // radix sort special case, since curr impl supports only unsigned
        original = algo_sorted = std_sorted = generate_unsorted_vector(true);
        std::sort(std_sorted.rbegin(), std_sorted.rend());

        // Run tests
        radix_sort(algo_sorted, -1, false);
        REQUIRE(algo_sorted == std_sorted);
    }
}

/*
    generate_unsorted_vector
    ------------------------
    Creates a vector of random size and populates it with random integers.
     Default for max_size is set in function declaration.
*/
vector<int> generate_unsorted_vector(const bool is_unsigned, int max_size) {
    vector<int> v;
    auto vector_size = (size_t) generate_random_int(1, max_size);
    v.reserve(vector_size);

    int min, max;

    if (is_unsigned)
    {
        min = std::numeric_limits<unsigned short>::min();
        max = std::numeric_limits<unsigned short>::max();
    }
    else
    {
        min = std::numeric_limits<short>::min();
        max = std::numeric_limits<short>::max();
    }

    for (int i = 0; i < (int) vector_size; i++) {
        v.push_back(generate_random_int(min, max));
    }
    return v;
}

/*
    generate_random_int
    -------------------
    Generates a random int between min and max.
*/
int generate_random_int(int min, int max) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<> int_range(min, max);
    return int_range(generator);
}
