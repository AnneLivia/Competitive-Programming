#include <iostream>
#include <vector>
#include <ctime>   // To use the range function to generate random numbers
#include <cstdlib> // To use the range function to generate random numbers
#include <chrono>
#include <thread> // To use sleep

/*
    What is a genetic algorithm?
    Genetic algorithm follows the principle of the natural evolution, where, the idea
    is to use those concepts of evolution to solve optimization problems.

    Optimization problems are: An optimization problem consists to find the best solution among all possible ones.

    According to the website: https://www.doc.ic.ac.uk/~nd/surprise_96/journal/vol1/hmw/article1.html
    Genetic Algorithm are adaptive heuristic ( is a technique designed for solving a problem more quickly,
    when classic methods are too slow, or for finding an approximate solution when classic methods fail to find any
    exact solution ) search algorithm based on the evolutionary ideas of natual selection
    and genetics.

    OneMax problem:

    N = [1, 0, 0, 1] -> each number of this vector is a gene, this array to a genetic algorithm is a Chromosome ("person")
    [1,0,0,1], [1,1,0,1], [0,0,1,1] -> population
    [1,0,0,1] -> genetic modification would be to modify a specific position of this "person" == [1,1,0,1]
    [1,0,0,1] x [1,1,0,1] = crossover, choose a position, and everything from the chosen position to the begin will be passed to the child, and the rest is from the second father
    == [ 1, 0, 0, 1] is the result of the crossover
    Each Chromosome has a score, the fitness, the score of onemax, is if the n is 4, the best solution [1,1,1,1].
    so the score of [1, 0, 0, 1] is 2,
    if [1,1,1,0] = score = 3.

    Genetic algorithm flowchart:
    initialize population -> evaluation -> selection -> crossover -> mutation -> back to initialize population.
                                |-> Done.

    maximize number of ones in a chromosome
*/

using namespace std;

typedef vector<int> vi;

// Parameters of the generic algorithm

int genes_number = 100; // Number of genes
int population_number = 50; // Number of the population
double mutation_prob = 0.2; // Probability of mutation
double cross_prob = 0.7; // Probability of crossover
int generation = 500; // Amount of generations
int tournament = 20; // Number of tournament

/*
    Tournament selection is a method of selecting an
    individual from a population of individuals.
    Tournament selection involves running several
    "tournaments" among a few individuals chosen at
    random from the population. The winner of each
    tournament (the one with the best fitness) is
    selected for crossover.
*/


vector<vi>population;

// Initialize the population
void initialize_population() {
    for(int i = 0; i < population_number; i++) {

        vi chromosome; // Creating a vector of int to store genes' number of 0 or 1
        for(int j = 0; j < genes_number; j++) { // The tam of each chromosome is the number of genes
            int number = rand() % 2; // Generate either 0 or 1
            chromosome.push_back(number); // Form a chromosome
        }

        population.push_back(chromosome);
    }
}

// Overloading the << operator
ostream& operator << (ostream& ostr, const vi& c) {
    for(int i = 0; i < (int)c.size(); i++) {
        ostr << c[i] << " ";
    }
    ostr << endl;

    return ostr;
}

// Show population
void show_population() {
    for(int i = 0; i < population_number; i++) {
        cout << population[i] << endl;
    }
}

// Get the score of the individual (fitness function)
int getScore(vi chromosome) {
    int sum = 0;

    for (int i = 0; i < genes_number; i++) {
        sum+=chromosome[i]; // add up all ones
    }

    return sum;
}

// Change according to some random position, if it's one, change it to 0, and so on.
void mutation(vi& chromosome) {
    // To the some position for a random mutation is from 0 to genes_number - 1, so:
    int gene = rand() % genes_number;
    chromosome[gene] = !chromosome[gene];
}

// Crossover
void crossover(int indexParent1, int indexParent2, vector<int>& offspring) {
    // Example how this is going to be done: [1,0,1,1] and  [1,1,1,0], we take a position, and from this position behind, we take from the parent 1 and the left from the parent 2

    int position = rand() % genes_number; // Each parent has genes_number amount of genes, to select a point, it's going to be check from 0 to genes_number

    // Getting from 0 to position of parent 1
    for(int i = 0; i <= position; i++) {
        offspring.push_back(population[indexParent1][i]);
    }

    // Getting from position to genes_number from parent 2
    for(int i = position + 1; i < genes_number; i++) {
        offspring.push_back(population[indexParent2][i]);
    }
}

// get the index of the best individual
int getBetter() {
    int best_index = 0, score;
    int best_score = getScore(population[0]);

    for(int i = 1; i < population_number; i++) {
        score = getScore(population[i]);
        if(score > best_score) {
            best_score = score;
            best_index = i;
        }
    }

    return best_index;
}

int main()
{

    srand(time(nullptr)); // Generate random numbers
    initialize_population(); // Initialize population

    for (int i = 0; i < generation; i++) { // Run through each generation

        for(int j = 0; j < tournament; j++) { // Crossovers

            // Calculate probability of crossover
            double probability = ((double)rand() / ((double)RAND_MAX + 1)); // Will generate a number from 0 to 1

            // If the probability is less than the crossover probability, continue...
            if(probability < cross_prob) {
                // Getting index of parent 1 and 2
                int parent1 = rand() % population_number; // Random parent 1
                int parent2 = parent1;
                while(parent1 == parent2) {
                    parent2 = rand() % population_number; // Getting the index for parent 2, provided that parent 1 and 2 are different
                }

                vi offspring; // creating offspring vector
                crossover(parent1, parent2, offspring); // Generating offspring

                // Calculating the probability of mutation
                probability = ((double)rand() / ((double)RAND_MAX + 1));

                if(probability < mutation_prob) {
                    mutation(offspring); // Applying a mutation to the offspring
                }

                // If the score of the offspring is better
                if(getScore(offspring) > getScore(population[parent1])) {
                    population[parent1] = offspring;
                }
            }
        }

        cout << "Generation: " << i + 1 << endl;
        cout << "Best: " << endl;
        cout << population[getBetter()] << endl;
        cout << "Score: " << getScore(population[getBetter()]) << endl;

        if(getScore(population[getBetter()]) == genes_number) // Best one was found
            break;

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
