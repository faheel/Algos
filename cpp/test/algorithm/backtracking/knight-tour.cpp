#include "third_party/catch.hpp"
#include "algorithm/backtracking/n_queens.hpp"

TEST_CASE("Base cases", "[backtracking][n_queens]") {
    // N = 0 (cannot place)
    KnightTour kt;
    kt.solve();
}