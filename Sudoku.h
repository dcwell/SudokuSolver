#ifndef CSS343_SUDOKU_SUDOKU_H
#define CSS343_SUDOKU_SUDOKU_H

#include <iostream>
#include "Puzzle.h"

using std::vector;
using std::pair;
using std::string;
using std::ostream;

class Sudoku: public Puzzle {
    friend ostream &operator<<(ostream &os, const Sudoku &Puzzle);
public:
    Sudoku();
    Sudoku(const Sudoku& Original);
    void showHints();
    bool read(const string& filename);
};

#endif //CSS343_SUDOKU_SUDOKU_H

// 9x9 grid with fixed hints and initialized data
// output operators will be used through puzzle inheritance
// read function that reads file and ignored anything not between 0 and 9 (first 81 integers)
// output method oututs as friendly output as shown in assignment description