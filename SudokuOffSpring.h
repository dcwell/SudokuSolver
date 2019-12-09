#ifndef CSS343_SUDOKU_SUDOKUOFFSPRING_H
#define CSS343_SUDOKU_SUDOKUOFFSPRING_H

#include "Reproduction.h"
#include "Population.h"

class SudokuOffSpring: public Reproduction {
public:
    SudokuOffSpring()= default;
    void reproduce(vector<Population::Individual>& population, int maxSize) override;
    Sudoku* makeOffSpring(Sudoku* puzzle);
};

#endif //CSS343_SUDOKU_SUDOKUOFFSPRING_H

//  implements "makeOffspring" for Sudoku objects which takes a Puzzle
//  and returns a new Puzzle