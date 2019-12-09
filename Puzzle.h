#ifndef CSS343_SUDOKU_PUZZLE_H
#define CSS343_SUDOKU_PUZZLE_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Puzzle {
 public:
    // Pure virtual function
    virtual bool read(const string&) = 0;

    // Default constructor
    Puzzle() = default;

    //Copy Constructor
    Puzzle(const Puzzle& oldPuzzle) {
        grid.resize(9);
        for (int i = 0; i < 9; i++) {
            grid[i].resize(9);
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j].first = oldPuzzle.grid[i][j].first;
                grid[i][j].second = oldPuzzle.grid[i][j].second;
            }
        }
    }

    virtual ~Puzzle() {
        grid.clear();
    }

    // For each method, check for out of bounds arguments
    // Getter and Setter methods to be used in other classes (grid is protected)
    inline int getFirst(int i, int j) const {
        if (i < 0 || j < 0 || i > 9 || j > 9) {
            return -1;
        }
        return grid[i][j].first;
    }
    inline int getSecond(int i, int j) const {
        if (i < 0 || j < 0 || i > 9 || j > 9) {
            return -1;
        }
        return grid[i][j].second;
    }
    inline void setFirst(int i, int j, int value) {
        if (i < 0 || j < 0 || i > 9 || j > 9) {
            cout << "Invalid input" << endl;
            return;
        }
        grid[i][j].first = value;
    }

protected:
    // store the sudoku puzzles cell number and whether it is a hint or not
    vector<vector<pair<int, bool>>> grid;
};

#endif //CSS343_SUDOKU_PUZZLE_H
