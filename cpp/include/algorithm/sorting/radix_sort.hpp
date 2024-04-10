/*
    Radix sort
    ----------
    Least significant digit radix sort is an efficient, non-comparative, integer
    sorting algorithm that sorts data with integer keys by grouping keys by the
    individual digits which share the same significant position and value.

    NOTE: This implementation of radix sort can be used to sort positive integers
    only.
*/

#ifndef RADIX_SORT_HPP
#define RADIX_SORT_HPP

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include "utils.hpp"

using std::vector;
using std::array;

/*
    count_sort
    ----------
    Performs count sort on the elements passed by radix_sort.

    Time complexity
    ---------------
    O(N), where N is the number of keys.

    Space complexity
    ----------------
    O(N), where N is the number of keys.
*/
void count_sort(vector<int>& values, const int extractor, const int mult_factor,
                const int add_factor, const bool to_show_state = false) {
    array<int, 10> counter{0};
    vector<int> output(values.size());

    auto get_digit = [&] (const int value) {
        return add_factor + (mult_factor * ((value / extractor) % 10));
    };

    for (int value: values) {
        counter[get_digit(value)]++;
    }
    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }
    for (int i = values.size() - 1; i >= 0; i--) {
        output[counter[get_digit(values[i])] - 1] = values[i];
        counter[get_digit(values[i])]--;
    }

    values = output;

    if (to_show_state) {
        display_state(values);
    }
}

/*
    max_in_vector
    -------------
    Returns the maximum value in a vector.
*/
int max_in_vector(const vector<int>& values) {
    return *max_element(values.begin(), values.end());
}

/*
    radix_sort_internal
    -------------------
    Performs least significant digit radix sort, making use of count_sort.

    Time complexity
    ---------------
    O(N), where N is the number of keys.

    Space complexity
    ----------------
    O(N), where N is the number of keys.
*/
void radix_sort_internal(vector<int>& values, const int mult_factor, const int add_factor,
                         const bool to_show_state = false) {
    int max_value = max_in_vector(values);

    // On each iteration of the following loop, extractor helps in getting the
    // next significant digit, which is (value / extractor) mod 10
    for (int extractor = 1; max_value / extractor > 0; extractor *= 10) {
        count_sort(values, extractor, mult_factor, add_factor, to_show_state);
    }
}

// Wrapper function
void radix_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    // The following factors depend on the sorting order
    int mult_factor = 1;
    int add_factor = 0;
    if (order == -1) {
        mult_factor = -1;
        add_factor = 9;
    }

    radix_sort_internal(values, mult_factor, add_factor, to_show_state);
}

#endif // RADIX_SORT_HPP
