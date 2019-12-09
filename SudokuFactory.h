#ifndef CSS343_SUDOKU_SUDOKUFACTORY_H
#define CSS343_SUDOKU_SUDOKUFACTORY_H

#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Sudoku.h"

class SudokuFactory : public PuzzleFactory {
public:
    Puzzle* createPuzzle();
    explicit SudokuFactory(Puzzle* puzzleFactory): PuzzleFactory(puzzleFactory) {
    }
    ~SudokuFactory() = default;
};

#endif //CSS343_SUDOKU_SUDOKUFACTORY_H

// The SudokuFactory uses a SudokuFitness object and
// implements "createPuzzle" to produce new Sudoku objects.