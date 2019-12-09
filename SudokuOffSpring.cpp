#include "Population.h"
#include "SudokuPopulation.h"
#include "Sudoku.h"
#include "PuzzleFactory.h"
#include "SudokuFactory.h"
#include "SudokuOffSpring.h"
#include <vector>
#include <utility>
#include <algorithm>

using std::sort;

void SudokuOffSpring::reproduce(vector<Population::Individual> &population,
                                const int maxSize) {
    // Tracks the number left after the cull
    int numMovingOn = population.size();

    // fills in the missing spaces with duplicates
    for (int i = 0; i < maxSize - numMovingOn; i++) {
        Population::Individual newInd(population.at(i % numMovingOn));
        population.push_back(newInd);
    }

    // mutates each puzzle in population
    for (int i = 0; i < maxSize; i++) {
        Sudoku* temp = population[0].puzzle;
        Sudoku* mutated = makeOffSpring(temp);
        population.erase(population.begin());
        Population::Individual mutatedInd;
        mutatedInd.puzzle = mutated;

        SudokuFitness* fitness = new SudokuFitness(mutated);
        mutatedInd.fitVal = fitness->howFit(mutated);
        population.push_back(mutatedInd);

        delete fitness;
        delete temp;
    }
    sort(population.begin(), population.end());
}

Sudoku* SudokuOffSpring::makeOffSpring(Sudoku* puzzle) {
    // Percentage represented as an integer
    int probablity = 5;

    Sudoku* temp = new Sudoku(*puzzle);
    // Iterate through each element in the puzzle
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // Check if the element is not a hint
            if (temp->getSecond(i, j) != 1) {
                // Apply probability to determine if element should be random
                if ((rand() % 100) < probablity) {
                    temp->setFirst(i, j, rand() % 9 + 1);
                }
            }
        }
    }
    return temp;
}
