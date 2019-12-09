#include "SudokuPopulation.h"
#include "SudokuOffSpring.h"
#include "Sudoku.h"
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <algorithm>


void SudokuPopulation::insert(Sudoku* sudoku) {
    if (population.size() != popSize) {
        // make an individual to insert into the population vector
        Individual newIndividual;

        // stores the fitness level
        int fitVal;

        // Assigns the fitness value
        SudokuFitness fitness(sudoku);
        fitVal = fitness.howFit(sudoku);

        // assigns the puzzle into the pair. Keeps address
        newIndividual.puzzle = new Sudoku(*sudoku);

        // Assigns the fitness value to the new individual
        newIndividual.fitVal = fitVal;

        // inserts the pair of (fitness, puzzle) into the population set
        population.push_back(newIndividual);

        // Sorts from least to greatest2
        sort(population.begin(), population.end());
        return;
    } else {
        cout << "Population full." << endl;
        return;
    }
}

void SudokuPopulation::cull(float botXPercentage) {
    int botX = botXPercentage * popSize;
    for (int i = 0; i < botX; i++) {
        Puzzle* temp = population[population.size()-1].puzzle;
        population.pop_back();
        // memory leaks with pop_back even with deleting temp.
        // Handles pointers very strangely. Creates more than one duplicate
        // sometimes
        delete temp;
    }
}

int SudokuPopulation::bestFitness() {
    if (population.size() == 0) {
        return -1;
    }
    return population[0].fitVal;
}

void SudokuPopulation::newGeneration(PuzzleFactory* pFactory, int genCount) {
    if (genCount == 0) {
        for (int i = 0; i < popSize; i++) {
            insert(dynamic_cast<Sudoku*>(pFactory->createPuzzle()));
        }
    } else {
        SudokuOffSpring repopulate;
        repopulate.reproduce(population, popSize);
    }
}

Puzzle* SudokuPopulation::bestIndividual() {
    return population[0].puzzle;
}
