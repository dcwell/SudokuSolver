#ifndef CSS343_SUDOKU_GENETICALGORITHM_H
#define CSS343_SUDOKU_GENETICALGORITHM_H

#include <iostream>
#include "Sudoku.h"
#include "Fitness.h"
#include "Population.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Reproduction.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "SudokuOffSpring.h"
#include "SudokuPopulation.h"
#include <chrono>
#include <string>

using std::istream;
using std::ostream;

class GeneticAlgorithm {
public:
    GeneticAlgorithm(int popArg, int genArg) {
        maxPop = popArg;
        genMax = genArg;
    }
    void compute(string filename);

private:
    int maxPop;
    int genMax;
};

#endif //CSS343_SUDOKU_GENETICALGORITHM_H



// argv[1] is population and argc[2] is num of generations

// first reads the file and creates first generation
//
// First ask the Population for the bestFitness, halting iterations if a solution
// has been found or if the maximum number of generations limit has been reached,
//
// command the Population to cull 90% of its Puzzles, and
//
// command the Population to reproduce a newGeneration.



// can choose to output up to 10 puzzles as it executes