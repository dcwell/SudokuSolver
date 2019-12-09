#include "GeneticAlgorithm.h"
#include "Sudoku.h"

using std::cout;
using std::endl;


void GeneticAlgorithm::compute(string filename) {
    Sudoku* originalPuzzle = new Sudoku();
    originalPuzzle->read(filename);

    SudokuFactory* sFactory = new SudokuFactory(originalPuzzle);
    SudokuPopulation sPopulation(maxPop);

    for (int i = 0; i < genMax; i++) {
        if (sPopulation.bestFitness() == 0) {
            cout << "Algorithm complete..." << endl;
            cout << "Best fitness: " << sPopulation.bestFitness() << endl;
            cout << "Solved Puzzle " << endl;
            cout << *dynamic_cast<Sudoku*>(sPopulation.bestIndividual()) << endl;
            delete originalPuzzle;
            delete sFactory;
            return;
        }
        sPopulation.newGeneration(sFactory, i);
        // sPopulation.outputPuzzles(i);
        sPopulation.cull(0.9);
        // cout << sPopulation.bestFitness() << endl;
    }

    delete originalPuzzle;
    delete sFactory;

    cout << "Here was the best puzzle after " << genMax
    << " generations, with population size " <<
    maxPop << ": (Fitness " << sPopulation.bestFitness() << ")" << "\n";
    cout << *dynamic_cast<Sudoku*>(sPopulation.bestIndividual()) << endl;
}
