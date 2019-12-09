#ifndef CSS343_SUDOKU_SUDOKUFITNESS_H
#define CSS343_SUDOKU_SUDOKUFITNESS_H

#include "Fitness.h"
#include "Puzzle.h"

class SudokuFitness : public Fitness{
public:
    SudokuFitness(Sudoku* puzzle) {
        fitLevel = howFit(puzzle);
    }
    int howFit(const Puzzle*);
    int getFitFromVect(vector<int>&);

    virtual ~SudokuFitness() {
    }

    int getFit() {
        return fitLevel;
    }

protected:
    int fitLevel;
};

#endif //CSS343_SUDOKU_SUDOKUFITNESS_H

// implements "howFit" for Sudoku objects