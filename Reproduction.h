#ifndef CSS343_SUDOKU_REPRODUCTION_H
#define CSS343_SUDOKU_REPRODUCTION_H

#include "Population.h"
#include "SudokuPopulation.h"
#include "Sudoku.h"
#include "PuzzleFactory.h"
#include "SudokuFactory.h"
#include <vector>
#include <utility>

using namespace std;

class Reproduction {
public:
    Reproduction() = default;
    virtual void reproduce(vector<Population::Individual>& population, int maxSize) = 0;
};

#endif //CSS343_SUDOKU_REPRODUCTION_H

// Reproduction is used by PuzzleFactory to create new Puzzles from old ones

// Reproduction and its subclasses are also implementations of the strategy
// design pattern. Reproduction subclasses must implement a "makeOffspring"
// method, which takes a Puzzle and returns a new Puzzle.