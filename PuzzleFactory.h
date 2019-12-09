#ifndef CSS343_SUDOKU_PUZZLEFACTORY_H
#define CSS343_SUDOKU_PUZZLEFACTORY_H

#include "Puzzle.h"

class PuzzleFactory {
public:
    // create puzzle will take in the original puzzle with hints and randomize
    // empty elements
    virtual Puzzle* createPuzzle() = 0;

    // Constructor will build the puzzle factory using the original puzzle
    // generated in the Puzzle Class through read()
    explicit PuzzleFactory(Puzzle* puzzleFactory) {
        this->originalPuzzle = puzzleFactory;
    }

    virtual ~PuzzleFactory() {
    }

protected:
    Puzzle* originalPuzzle;
};

#endif //CSS343_SUDOKU_PUZZLEFACTORY_H

// A PuzzleFactory is provided at construction time with a
// reproduction object that it uses to create new instances of Puzzle