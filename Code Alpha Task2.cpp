#include <iostream>
using namespace std;

const int SIZE = 9;

// Print Sudoku Grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if number can be placed
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {

    // Row Check
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num)
            return false;
    }

    // Column Check
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num)
            return false;
    }

    // 3x3 Box Check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

// Backtracking Function
bool solveSudoku(int grid[SIZE][SIZE]) {

    int row, col;
    bool emptyFound = false;

    // Find Empty Cell
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {

            if (grid[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }

        if (emptyFound)
            break;
    }

    // Puzzle Solved
    if (!emptyFound)
        return true;

    // Try numbers 1-9
    for (int num = 1; num <= 9; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int grid[SIZE][SIZE] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    cout << "Original Sudoku:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {

        cout << "\nSolved Sudoku:\n";
        printGrid(grid);

    }
    else {
        cout << "No Solution Exists!";
    }

    return 0;
}