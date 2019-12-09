#ifndef CSS343_SUDOKU_FITNESS_H
#define CSS343_SUDOKU_FITNESS_H

#include "Puzzle.h"
#include "Sudoku.h"

class Fitness {
public:
    virtual int howFit(const Puzzle*) = 0;
};
#endif //CSS343_SUDOKU_FITNESS_H

// Fitness is used by a Population to evaluate individual Puzzles
// Fitness and its subclasses are implementations of the strategy  design pattern

// Fitness subclasses must implement a "howFit" method, which takes a
// Puzzle (subclass) object and returns an int