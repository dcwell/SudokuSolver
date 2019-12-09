#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include "Puzzle.h"
#include "Sudoku.h"

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::endl;

// default constructor
Sudoku::Sudoku() {
    // initializes the 9x9 puzzle as containing all 0s and no hints
    grid.resize(9);
    for (int i = 0; i < grid.size(); i++) {
        grid[i].resize(9);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j].first = 0;
            grid[i][j].second = false;
        }
    }
}

// copy constructor
Sudoku::Sudoku(const Sudoku& original) : Puzzle(original) {
}

bool Sudoku::read(const string& filename) {
    ifstream fin;

    // opens default.txt
    fin.open(filename);

    // checks if file is open, if not, returns false
    if (!fin.is_open()) {
        return false;
    }

    // used to store each getline from the file
    string fileInfo;

    // stores all of the integers as characters in a string
    string integers;

    // tracks the number of integers found in the file up to 81
    int nums = 0;

    // while there is data still unread perform the following
    while (getline(fin, fileInfo)) {
        // resets the count for new getline call
        int count = 0;

        for (int i = 0; i < fileInfo.size() && nums < 81; i++) {
            if (isdigit(fileInfo[i])) {
                nums++;
                integers += fileInfo[i];
            }
        }
    }

    // iterates through integer string
    int sCount = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j].first = integers[sCount] - '0';
            sCount++;
            if (grid[i][j].first != 0) {
                grid[i][j].second = true;
            }
        }
    }
    fin.close();
    return true;
}

void Sudoku::showHints() {
    // displays the puzzle with its hint or non-hint values
    Sudoku temp(*this);
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j++) {
            temp.grid[i][j].first = grid[i][j].second;
        }
    }
    cout << temp << endl;
}

ostream &operator<<(ostream &os, const Sudoku &sudoku) {
    string line = "+-------+-------+-------+";

    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            os << line << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                os << '|';
            }
            else if (j % 3 == 0) {
                os << ' ';
                os << '|';
            }
            os << ' ' << sudoku.grid[i][j].first;
            if (j == 8) {
                os << ' ' << '|';
            }
        }
        os << endl;
    }
    os << line << endl;
    return os;
}
