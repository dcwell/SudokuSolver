#include "SudokuFitness.h"
#include "Puzzle.h"
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

// Mesures the fitness level of a given puzzle.
// Fitness is determined by the number of collisions in each row, col,
// and block calculated separately. Ex: 1 4 1 2 9 4 2 1 6   represents a
// single row. there are 4 collisions in this case. Three 1s cause 2 collisions,
// two 2s cause one collision, and two 4s cause another.

int SudokuFitness::getFitFromVect(vector<int>& vect) {
    int collisions = 0;
    int temp = 0;

    // sorts the vector, pops from the back and stores that value
    // if the value stored is the same as the next value, add to the collision.
    sort(vect.begin(), vect.end());
    while (!vect.empty()) {
        if (temp == vect[vect.size() - 1]) {
            collisions++;
            vect.pop_back();
        } else {
            temp = vect[vect.size() - 1];
            vect.pop_back();
        }
    }
    return collisions;
}

int SudokuFitness::howFit(const Puzzle* sudoku) {
    // Vector stores all elements in a given row, column, or 3x3 block
    vector<int> rowVect;
    vector<int> colVect;
    vector<int> blockVect;

    // Zero initialize all fitness measurements
    int colFit(0), rowFit(0), blockFit(0);

    // Getting the fitness from the blocks
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    blockVect.push_back(sudoku->getFirst(i + x, j + y));
                }
            }
            blockFit += getFitFromVect(blockVect);
        }
    }

    // Getting the fitness from the rows
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            rowVect.push_back(sudoku->getFirst(i, j));
        }
        rowFit += getFitFromVect(rowVect);
    }

    // Getting the fitness from the columns
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            colVect.push_back(sudoku->getFirst(j, i));
        }
        colFit += getFitFromVect(colVect);
    }

    // combines all fitnesses into one
    return colFit + rowFit + blockFit;
}
