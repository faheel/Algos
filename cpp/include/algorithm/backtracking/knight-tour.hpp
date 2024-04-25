/*
    Knight Tour problem
    ----------------
	Find a sequence of moves for the knight on a chessboard such that it visits every square on the board exactly one time

    Time complexity
    ---------------
    O(8^(n^2)), where N is the size of the chessboards.

    Space complexity
    ----------------
    O(N^2), where N is the size of the chessboards.
*/

#ifndef KNIGHT_TOUR_HPP
#define KNIGHT_TOUR_HPP

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> Board;

const int N = 8;		// N is the number of cells per side. N = 8 means a chessboard of 64 cells.	
int moveCount = 0;		// Counter for number of movements.

class KnightTour {
private:
    Board board;	// Instantiate a board.
	// Arrays for the possible moves, either in x-axis or y-axis, with the numbers of cells the Knight can move in each axis.
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool isSafe(int x, int y) {
        return (x >= 0 && y >= 0 && x < N && y < N && !board[x][y]);
    }
	/**
	* @param x : x-axis of the current position of the Knight.
	* @param y : y-axis of the current position of the Knight.
	* @param movei : represents the current move number to keep track of the number of movements.
	*/
    bool solveKTUtil(int x, int y, int movei) {
        int next_x, next_y;
        if (movei == N * N)	// Max is 64 moves.
            return true;	// End of recursives calls.	

        for (int k = 0; k < 8; ++k) {
            next_x = x + xMove[k];
            next_y = y + yMove[k];
            if (isSafe(next_x, next_y)) {
                board[next_x][next_y] = true;	// Mark the cell as visited by the Knight.
                if (solveKTUtil(next_x, next_y, movei + 1))
                    return true;
                else
                    board[next_x][next_y] = false; // Backtrack
            }
        }
        return false;
    }

public:
    KnightTour() {
		// Initialize to false all the cells if the board. No cell is visited by the Knight at the very beginning.
        board.assign(N, vector<bool>(N, false));
    }
	/**
	* Solve method to be called to find a solution of the problem. By default, we start at the top-left corner.
	* */
    bool solve() {
        // Starting from the top-left corner
        board[0][0] = true;

        // Start from position (0, 0) and explore all tours
        if (!solveKTUtil(0, 0, 1)) {
            cout << "Solution does not exist" << endl;
            return false;
        } else {
            cout << "Solution: \n";
            printSolution();
            return true;
        }
    }

    void printSolution() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << board[i][j] << "\t";
            cout << endl;
        }
    }
};

#endif  // KNIGHT_TOUR_HPP
