/*
    Euclid's greatest common divisor algorithm
    ------------------------------------------
    The basic Euclidean algorithm is used to find the greatest common divisor of two
    numbers, a and b. The Euclidean algorithm is based on the principle that the greatest
    common divisor of two numbers does not change if the larger number is replaced by its
    difference with the smaller number.

    Time complexity
    ---------------
    O(log10(m)), where m = min(a, b) is the smaller of the input integers a and b

    Space complexity
    ----------------
    O(1)
*/

/*
    greatest_common_divisor
    -----------------------
    Returns the greatest common divisor of integers a and b.
*/

#ifndef GREATEST_COMMON_DIVISOR_EFFICIENT_HPP
#define GREATEST_COMMON_DIVISOR_EFFICIENT_HPP

int greatest_common_divisor_efficient(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a == 0) {
        return b;
    }

    int r;
    while (a > 0) {
        r = b % a;
        b = a;
        a = r;
    }
    return b
}

#endif // GREATEST_COMMON_DIVISOR_EFFICIENT_HPP
