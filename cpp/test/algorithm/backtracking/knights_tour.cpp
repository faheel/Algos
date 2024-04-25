#include "third_party/catch.hpp"
#include "algorithm/backtracking/knights_tour.hpp"

TEST_CASE("Base cases for Knights Tour", "[backtracking][knights_tour]") {
    // N = 1 (trivial case where a single move is the solution)
    KnightsTourSolver k1(1);
    REQUIRE(k1.has_solution() == true);
    Board expected1 = {{0}};
    REQUIRE(k1.get_solution() == expected1);

    // N = 2 (No solution possible)
    KnightsTourSolver k2(2);
    REQUIRE(k2.has_solution() == false);
    
    // N = 3 (No solution possible)
    KnightsTourSolver k3(3);
    REQUIRE(k3.has_solution() == false);
}

TEST_CASE("Small solvable cases", "[backtracking][knights_tour]") {
    // N = 4 (No solution)
    KnightsTourSolver k4(4);
    REQUIRE(k4.has_solution() == false);

    // N = 5 (Solvable)
    KnightsTourSolver k5(5);
    REQUIRE(k5.has_solution() == true);
}

TEST_CASE("Standard chessboard case", "[backtracking][knights_tour]") {
    // N = 8 (Standard chessboard)
    KnightsTourSolver k8(8);
    REQUIRE(k8.has_solution() == true);
}

TEST_CASE("Checking specific solution properties", "[backtracking][knights_tour]") {
    // N = 5, known solutions should end at specific positions to verify path correctness
    KnightsTourSolver k5(5);
    if (k5.has_solution()) {
        Board solution = k5.get_solution();
        // Ensure the tour ends correctly, you might want to check starting and ending positions
        // For a 5x5 board, depending on the algorithm, you could check if the last move
        // (which should be 24 in 0-indexed) is at a position that could theoretically
        // lead back to the start for a closed tour or just verify it exists somewhere
        int last_move = 24;
        bool found_last_move = false;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (solution[i][j] == last_move) {
                    found_last_move = true;
                    break;
                }
            }
            if (found_last_move) break;
        }
        REQUIRE(found_last_move);
    }
}
