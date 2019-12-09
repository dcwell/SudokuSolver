#ifndef CSS343_SUDOKU_POPULATION_H
#define CSS343_SUDOKU_POPULATION_H

#include <vector>
#include <set>
#include <utility>
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Sudoku.h"

using std::vector;
using std::set;

class Population {
 public:

    struct Individual {
        int fitVal;
        Sudoku* puzzle;

        // created for vector sort to use. Stores duplicates
        bool operator <(const Individual& rhs) const {
            return (this->fitVal < rhs.fitVal);
        }

        Individual() = default;

        // constructs using only a sudoku pointer and its fitness level
        Individual(const Sudoku* sudoku, int fitness) {
            puzzle = new Sudoku(*sudoku);
            fitVal = fitness;

        }

        // copy constructor
        Individual(const Individual &other) {
            puzzle = new Sudoku(*other.puzzle);
            fitVal = other.fitVal;
        }

        ~Individual() {
            //delete puzzle;
            // this should delete but did not have time to fix push_back()
            // so there were segmentation fault issues
        }
    };
    // Returns the best fitness value
    virtual int bestFitness() = 0;

    // Returns the puzzle with the highest fitness
    virtual Puzzle* bestIndividual() = 0;

    // Removes the bottom X number of Puzzles from the population
    virtual void cull(float botXPercentage) = 0;

    // Used the topX puzzles to generate up to the max population
    virtual void newGeneration(PuzzleFactory*, int) = 0;

    // Created a population with a given size and never exceeds it
    Population(int size) {
        popSize = size;
    }

    // clears the vector of individuals
    virtual ~Population() {
        Population::Individual temp;
        while (!population.empty()) {
            temp = *population.begin();
            population.erase(population.begin());
            delete temp.puzzle;
        }
    }

 protected:
    // Stores the puzzles as a set of pairs to organize by their
    // integer value later (their fitness) and gives easy options for
    // sorting, inserting, and deleting
    vector<Individual> population;
    int popSize;
};

#endif //CSS343_SUDOKU_POPULATION_H

// population is a container for a number of puzzles. Use a vector of puzzles
// can use the fitness strategy to evaluate each puzzle and organize them
// Uses the strategy when commanded to by the genetic algorithm
// it can cull puzzles from the population
// Has constructors that create initial randomized puzzles
// new generation mrthod that creats x number of new puzzles using the top 10%
// best fitness returns the lowest fitness score(best score)
// best individual returns the puzzle with the best fitness