#ifndef CSS343_SUDOKU_SUDOKUPOPULATION_H
#define CSS343_SUDOKU_SUDOKUPOPULATION_H

#include "Sudoku.h"
#include "Population.h"
#include "SudokuFitness.h"
#include <vector>

using std::vector;

class SudokuPopulation: public Population {
public:
    // Returns the fitness value of the best puzzle
    int bestFitness();

    // Returns the puzzle with the best fitness score
    Puzzle* bestIndividual();

    // Removes the bottom X number of puzzle based off fitness
    void cull(float botXPercentage);

    // Initialized the population to a designated size
    explicit SudokuPopulation(int size) : Population(size) {
    }

    // Inserts a passed in puzzle into the population, shouldnt change original
    void insert(Sudoku* sudoku);
  
    void newGeneration(PuzzleFactory* pFactory, int genCount);

    virtual ~SudokuPopulation() {
    }

    void outputPuzzles(int generation) {
        cout << "Generation: " << generation << endl;
        for (int i = 0; i < popSize; i++) {
            cout << "Puzzle : " << i << " with fitness " << population[i].fitVal << endl;
            cout << *population[i].puzzle;
        }
    }
};

#endif //CSS343_SUDOKU_SUDOKUPOPULATION_H

// this class implements all of the functions shown in population.h
// uses sudokuFitness and sudokuFactory to accomplish its tasksks