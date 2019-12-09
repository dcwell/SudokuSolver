// Authors: Ryan Larson and Denali Cornwell
// Date of Submission: 6/11/2019

#include <iostream>
#include "Fitness.h"
#include "GeneticAlgorithm.h"
#include "Population.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Reproduction.h"
#include "Sudoku.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "SudokuOffSpring.h"
#include "SudokuPopulation.h"
#include <chrono>
#include <string>

using std::cout;
using std::endl;

void test_sudoku() {
    Sudoku* sudoku = new Sudoku();
    sudoku->read("default.txt");

    Sudoku* sudoku2 = new Sudoku(*sudoku);
    cout << sudoku << endl;
    cout << sudoku2 << endl;

    cout << *sudoku << endl;

    cout << sudoku->getFirst(0, 0) << endl;
    sudoku->setFirst(0, 0, 9);
    cout << sudoku->getFirst(0, 0) << endl;

    cout << *sudoku << endl;

    delete sudoku;
    delete sudoku2;
}

void test_factory() {
    Sudoku* sudoku1 = new Sudoku();
    sudoku1->read("default.txt");

    SudokuFactory* sFactory = new SudokuFactory(sudoku1);

    for (int i = 0; i < 20; i++) {
        Sudoku *sudoku2 = dynamic_cast<Sudoku *>(sFactory->createPuzzle());
        cout << sudoku2 << endl;
        // When deleting, memory addresses are different
        delete sudoku2;
    }
    delete sudoku1;
    delete sFactory;
}

void test_fitness() {
    Sudoku* sudoku1 = new Sudoku();
    sudoku1->read("default.txt");

    SudokuFitness* fitness = new SudokuFitness(sudoku1);
    cout << fitness->howFit(sudoku1) << endl;

    cout << sudoku1 << endl;
    cout << *sudoku1 << endl;

    delete fitness;
}

void test_reproduction() {
    Sudoku* sudoku = new Sudoku();
    sudoku->read("default.txt");

    SudokuOffSpring* reproduction = new SudokuOffSpring();
    vector<Population::Individual> population;

    population.emplace_back(sudoku, SudokuFitness(sudoku).getFit());
    reproduction->reproduce(population, 5);
    for (const Population::Individual& ind : population) {
        cout << ind.puzzle << endl;
        cout << ind.fitVal << endl;
    }
    return;
}

void test_population() {
    Sudoku* sudoku = new Sudoku();
    sudoku->read("default.txt");

    SudokuFactory* sFactory = new SudokuFactory(sudoku);

    SudokuPopulation sPopulation(10);

    for (int i = 0; i < 10; i++) {
        sPopulation.insert(dynamic_cast<Sudoku*>(sFactory->createPuzzle()));
    }

    cout << sPopulation.bestFitness() << endl;
    cout << sPopulation.bestIndividual() << endl;

    sPopulation.cull(.80);
    sPopulation.newGeneration(sFactory, 5);

    cout << sPopulation.bestFitness() << endl;
    cout << sPopulation.bestIndividual() << endl;
}

int main(int argc, char *argv[]) {
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    srand(time(NULL));

    GeneticAlgorithm geneticAlgorithm(atoi(argv[1]), atoi(argv[2]));
    geneticAlgorithm.compute("default.txt");

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();

    // Find elapsed time
    std::chrono::duration<double> elapsed = finish - start;

    // Output elapsed time
    cout << "Elapsed time: " << elapsed.count() << " s\n";
    return 0;
}
