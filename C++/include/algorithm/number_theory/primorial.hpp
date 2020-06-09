/*
    Primorial
    ---------
    Calculate the primorial Pn# of the nth prime number Pn.
    Pn# is defined as the product of the first n primes.

    Time complexity
    ---------------
    O(Pn^2) where Pn is the nth prime number.

    Space complexity
    ----------------
    O(N).
*/

#ifndef PRIMORIAL_HPP
#define PRIMORIAL_HPP

#include <climits>
#include <vector>

typedef unsigned long long int ULL;

// primorial_Pn(Pn) where Pn > 47 goes beyond the range of ULL
const unsigned int MAX_P_N = 47;

// primorial_n(n) where n > 15 goes beyond the range of ULL
const unsigned int MAX_N = 15;

// returns 0 if Pn is not a prime number or if Pn# is too big to fit in an 
// ULL. returns the primorial Pn# otherwise
ULL primorial_Pn(unsigned int p_n) {
    if (p_n < 2) {
        return 0;
    }

    std::vector<unsigned int> primes;
    
    ULL product = 1;

    for (unsigned int i = 2; i <= p_n; i++) {
        bool is_prime = true;
        for (std::vector<unsigned int>::iterator it = primes.begin(); is_prime
            && it != primes.end(); it++) {
            if (i % *it == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {            
            // check for unsigned integer wraparound
            if (ULLONG_MAX / product < i) {
                return 0;
            } else {
                product *= i;
                primes.push_back(i);
            }
        }
    }

    // make sure Pn was a prime nubmer
    if (primes[primes.size()-1] != p_n) {
        return 0;
    }

    return product;
}

// returns 0 if n is 0 or if Pn# is too big to fit in an ULL. 
// returns the primorial Pn# otherwise
ULL primorial_n(unsigned int n) {
    if (n < 1) {
        return 0;
    }

    std::vector<unsigned int> primes;
    
    ULL product = 1;

    for (unsigned int i = 2; primes.size() < n; i++) {
        bool is_prime = true;
        for (std::vector<unsigned int>::iterator it = primes.begin(); is_prime
            && it != primes.end(); it++) {
            if (i % *it == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {            
            // check for unsigned integer wraparound
            if (ULLONG_MAX / product < i) {
                return 0;
            } else {
                product *= i;
                primes.push_back(i);
            }
        }
    }

    return product;
}

#endif // PRIMORIAL_HPP
