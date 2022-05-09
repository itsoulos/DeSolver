# ifndef __GPOPULATION__H
# include <gprogram.h>
# include <vector>
using namespace std;

/**
 * @brief The GPopulation class  represents the population of
 *	the genetic algorithm. It uses the class
 *	program to obtain fitness values, but it
 *	is nothing more than a simple implementation
 *	of a genetic algorithm.
 */
class GPopulation
{
	private:
        /**
         * @brief children  An auxiliary array, which holds the children produced
         *			 by the process of crossover.
         */
		int		**children;
        /**
         * @brief genome  The main array, which holds the chromosomes of the population.
         *			 Each chromosome is a set of production rules, used in the
         *			 process of creating programs.
         */
		int		**genome;
        /**
         * @brief fitness_array A double array, which holds the fitness value of each chromosome.
         */
		double 		*fitness_array;
        /**
         * @brief mutation_rate  A double variable which is between 0 and 1 and it denotes the
         *	                 rate for the mutation events. Usually, the value of this
         *	                 variable must be lower than 10%(0.1).
         */
        double		mutation_rate;
        /**
         * @brief selection_rate A double variable which is between 0 and 1 and it denotes the
         *			 percent of the genomes that will pass without changes to the
         *			 next generation. Usually, the value of this variable must be
         *			 between 10% and 30%.
         */
        double selection_rate;
        /**
         * @brief tournament_size  An integer variable, which denotes the amount of genomes that will
         *	                 be selected in the process of the crossover, in order to obtain a
         *	                 parent for crossover. Usually, the value of this variable is 4 or 8.
         *	genome_count:	 The amount of the genomes in the population.
         */
        int		tournament_size;
        /**
         * @brief genome_count number of chromosomes
         */
        int genome_count;
        /**
         * @brief genome_size The size of each chromosome in the population.
         */
        int genome_size;
        /**
         * @brief generation  The  consecutive number of the generation.
         */
        int generation;
        /**
         * @brief program  A pointer to the GProgram, for which the population must discover
         *		 	 the best program according to the fitness value. The best program of
         *		 	 the population is that with the highest fitness value. The user must
         *		 	 have supplied to necessary memory to the program, before he pass it
         *		 	 to the population.
         */
		GProgram	*program;

        vector<GProgram*> ompProgram;
        /**
         * @brief localSearch performs a local search for the chromosome at pos position.
         * @param pos
         */
		void	localSearch(int pos);
        /**
         * @brief fitness
         * @param g
         * @return  the associated fitness value for the genome g. It uses the
         *			 method fitness of the GProgram pointed by the pointer program.
         */
		double 	fitness(vector<int> &g);
        /**
         * @brief select sorts the tables genome and fitness_array according to the value of
         *			 the fitness_array. The genomes with the highest value of fitness go to
         *			 the beginning of the table genome. This process is performed just before
         *			 the crossover procedure.
         */
		void	select();
        /**
         * @brief crossover creates the children, that will replace the worst individuals in
         *			 the population.
         */
		void	crossover();
        /**
         * @brief mutate For every genome and for every element in the genome it selects a
         *			 double value in the range [0,1]. If that value is less than or
         *			 equal to mutation rate, then it randomly changes the element.
         */
		void	mutate();
        /**
         * @brief calcFitnessArray For every genome it computes the associated fitness value and it stores
         *			  it to the corresponding position in the fitness_array. This processes is
         *			  performed before the application of the genetic operators.
         */
		void	calcFitnessArray();
	public:
        /**
         * @brief GPopulation The default constructor of the class. It
         *					creates gcount genomes. Each genome's size
         *					is set to gsize. It sets the pointer program
         *					to p. Every genome is randomly initialized.
         * @param gcount
         * @param gsize
         * @param p
         */
		GPopulation(int gcount,int gsize,GProgram *p);

        GPopulation(int gcount,int gsize,vector<GProgram*> p);
        /**
         * @brief getGeneration
         * @return the  consecutive number of
         *					the generation.
         */
		int	getGeneration() const;
        /**
         * @brief getCount
         * @return he amount of chromosomes in the population.
         */
		int	getCount() 	const;
        /**
         * @brief getSize
         * @return  the size of each chromosome.
         */
		int	getSize() 	const;

        /**
         * @brief nextGeneration  applies the genetic operators to the
         *					population and it advances the generation counter.
         */
		void	nextGeneration();
        /**
         * @brief setMutationRate sets the value of the mutation_rate to r, if
         *					r has value between 0 and 1.
         * @param r
         */
		void	setMutationRate(double r);
        /**
         * @brief setSelectionRate sets the value of the selection_rate  to r, if
         *					r has value between 0 and 1.
         * @param r
         */
		void	setSelectionRate(double r);
        /**
         * @brief getSelectionRate the value of the selection_rate.
         * @return
         */
		double	getSelectionRate() 	const;
        /**
         * @brief getMutationRate the value of the mutation_rate.
         * @return
         */
		double	getMutationRate() 	const;
        /**
         * @brief getBestFitness
         * @return the best fitness discovered so far.
         */
		double	getBestFitness() 	const;
        /**
         * @brief evaluateBestFitness evaluates the GProgram pointed by program in
         *					the best chromosome.
         * @return
         */
		double	evaluateBestFitness();

        /**
         * @brief getTournamentSize
         * @return the size of the tournament.
         */
		int	getTournamentSize()	const;
        /**
         * @brief setTournamentSize sets the tournament_size to n, if n is positive
         *					and less than genome_count.
         * @param n
         */
		void	setTournamentSize(int n);

        /**
         * @brief getBestGenome
         * @return the best chromosome in the population. This
         *					chromosome is located in the first place of table genome,
         *					because we use elitism.
         */
		vector<int> getBestGenome() 	const;
		~GPopulation();
		
};
# define __GPOPULATION__H
# endif
