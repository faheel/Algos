/*
    Binary search
    -------------
    A searching algorithm that finds the index of a target value within a
    sorted array using divide and conquer.

    Time complexity
    ---------------
    O(log(N)), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <vector>

/*
    binary_search
    -------------
    It compares the target value to the middle element of the array; if they
    are unequal, the half in which the target cannot lie is eliminated and the
    search continues on the remaining half until it is successful. If the search
    ends with the remaining half being empty, the target is not in the array.
*/

template <typename T>
int binary_search(const T& value, const std::vector<T>& sorted_values,
        const int low, const int high) {
    
    int mid = low + (high - low) / 2;

    if (value == sorted_values[mid])
        return mid;
    else if (low < high) {
        if (value < sorted_values[mid]) {
            // value must be between indices low and mid-1, if exists
            return binary_search(value, sorted_values, low, mid - 1);
        }
        else if (value > sorted_values[mid]) {
            // value must be between indices mid+1 and high, if exists
            return binary_search(value, sorted_values, mid + 1, high);
        }
    }

    return -1;
}


/*
    binary_search
    -------------
    Convenience function for binary search that requires minimal arguments.
*/

template <typename T>
int binary_search(const T& value, const std::vector<T>& sorted_values) {
    if (sorted_values.size() == 0)
        return -1;
    
    return binary_search(value, sorted_values, 0, sorted_values.size() - 1);
}

#endif // BINARY_SEARCH_HPP
