/*
    Knight's Tour Problem
    ----------------
    Find a sequence of moves for a knight on a chessboard
    such that the knight visits every square exactly once.

    Time complexity
    ---------------
    O(8^(N^2)), where N is the length of the chess board

    Space complexity
    ----------------
    O(N^2), where N is the length of the chess board.
*/

#ifndef KNIGHTS_TOUR_HPP
#define KNIGHTS_TOUR_HPP

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Board;

const int MAX_KNIGHT_MOVES = 8;
const int moves_x[MAX_KNIGHT_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
const int moves_y[MAX_KNIGHT_MOVES] = {1, 2, 2, 1, -1, -2, -2, -1};

/*
    KnightsTourSolver
    -----------------
    Wrapper class for solving the Knight's Tour problem.
*/

class KnightsTourSolver {
    size_t N;
    bool is_solved;
    Board solution;

public:
    KnightsTourSolver(const size_t);
    bool has_solution() const;
    Board get_solution() const;
    void print_solution() const;
    void demonstrate_solution(); // Added for direct demonstration

private:
    void solve();
    bool find_tour(Board&, int, int, int);
    bool is_safe(const Board&, int, int) const;
};

/*
    Constructor
    -----------
*/

KnightsTourSolver::KnightsTourSolver(const size_t board_size) {
    N = board_size;
    solution.resize(N, std::vector<int>(N, -1));
    is_solved = false;
    solve();
}

/*
    Public interface
    ==========================================================================
*/

bool KnightsTourSolver::has_solution() const {
    return is_solved;
}

Board KnightsTourSolver::get_solution() const {
    return solution;
}

void KnightsTourSolver::print_solution() const {
    for (const auto& row : solution) {
        for (int num : row) {
            std::cout.width(4);
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}

void KnightsTourSolver::demonstrate_solution() {
    if (has_solution()) {
        std::cout << "A solution exists for the " << N << "x" << N << " board:\n";
        print_solution();
    } else {
        std::cout << "No solution exists for the " << N << "x" << N << " board.\n";
    }
}

/*
    Private methods
    ==========================================================================
*/

void KnightsTourSolver::solve() {
    solution[0][0] = 0; // Start from the top-left corner
    if (find_tour(solution, 0, 0, 1)) {
        is_solved = true;
    }
}

bool KnightsTourSolver::find_tour(Board& board, int x, int y, int move_i) {
    if (move_i == N * N)
        return true;

    for (int k = 0; k < MAX_KNIGHT_MOVES; k++) {
        int next_x = x + moves_x[k];
        int next_y = y + moves_y[k];
        if (is_safe(board, next_x, next_y)) {
            board[next_x][next_y] = move_i;
            if (find_tour(board, next_x, next_y, move_i + 1))
                return true;
            board[next_x][next_y] = -1; // backtrack
        }
    }

    return false;
}

bool KnightsTourSolver::is_safe(const Board& board, int x, int y) const {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1;
}

/*
    Test or Demonstrate the Knight's Tour solution without a main function.
*/

int main() {
    int board_size = 8; // Standard chessboard size
    KnightsTourSolver solver(board_size);
    solver.demonstrate_solution();
    return 0;
}

#endif // KNIGHTS_TOUR_HPP
