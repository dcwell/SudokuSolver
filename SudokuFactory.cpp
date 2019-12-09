#include "SudokuFactory.h"
#include "Puzzle.h"
#include <cstdlib>
#include "Sudoku.h"

Puzzle* SudokuFactory::createPuzzle() {
    Sudoku* newPuzzle = new Sudoku(*dynamic_cast<Sudoku*>(originalPuzzle));
    int random;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            random = rand() % 9 + 1;
            if (newPuzzle->getSecond(i, j) == 0) {
                newPuzzle->setFirst(i, j,random);
            }
        }
    }

    return newPuzzle;
}
