# ifndef __GPOPULATION__H
# include <gprogram.h>

/*	CLASS DESCRIPTION
 *	=================
 *	This class represents the population of 
 *	the genetic algorithm. It uses the class
 *	program to obtain fitness values, but it 
 *	is nothing more than a simple implementation
 *	of a genetic algorithm.
 * */


class GPopulation
{
	private:
		/*	PRIVATE FIELDS
		 *	===============
		 *	genome:		 The main array, which holds the genomes of the population.
		 *			 Each genome is a set of production rules, used in the 
		 *			 process of creating programs.
		 *	children:	 An auxiliary array, which holds the children produced
		 *			 by the process of crossover.
		 *	fitness_array:	 A double array, which holds the fitness value of each genome.
		 *	mutation_rate:	 A double variable which is between 0 and 1 and it denotes the
		 *	                 rate for the mutation events. Usually, the value of this 
		 *	                 variable must be lower than 10%(0.1).
		 *	selection_rate:  A double variable which is between 0 and 1 and it denotes the
		 *			 percent of the genomes that will pass without changes to the
		 *			 next generation. Usually, the value of this variable must be
		 *			 between 10% and 30%.
		 *	tournament_size: An integer variable, which denotes the amount of genomes that will
		 *	                 be selected in the process of the crossover, in order to obtain a
		 *	                 parent for crossover. Usually, the value of this variable is 4 or 8.
		 *	genome_count:	 The amount of the genomes in the population.
		 *	genome_size:     The size of each genome in the population.
		 *	generation:	 The  consecutive number of the generation.
		 *	program:	 A pointer to the GProgram, for which the population must discover
		 *		 	 the best program according to the fitness value. The best program of
		 *		 	 the population is that with the highest fitness value. The user must
		 *		 	 have supplied to necessary memory to the program, before he pass it 
		 *		 	 to the population.
		 *	fitness(g):	 It returns the associated fitness value for the genome g. It uses the
		 *			 method fitness of the GProgram pointed by the pointer program.
		 *	select():	 It sorts the tables genome and fitness_array according to the value of
		 *			 the fitness_array. The genomes with the highest value of fitness go to
		 *			 the beginning of the table genome. This process is performed just before
		 *			 the crossover procedure.
		 *	crossover():	 It creates the children, that will replace the worst individuals in 
		 *			 the population.
		 *	mutate():	 For every genome and for every element in the genome it selects a
		 *			 double value in the range [0,1]. If that value is less than or 
		 *			 equal to mutation rate, then it randomly changes the element.
		 *	calcFitnessArray():For every genome it computes the associated fitness value and it stores
		 *			  it to the corresponding position in the fitness_array. This processes is
		 *			  performed before the application of the genetic operators.
		 * */
		int		**children;
		int		**genome;
		double 		*fitness_array;
		double		mutation_rate,selection_rate;
		int		tournament_size, genome_count, genome_size, generation;
		GProgram	*program;

		double 	fitness(vector<int> &g);
		void	select();
		void	crossover();
		void	mutate();
		void	calcFitnessArray();
	public:
		/*	PUBLIC FIELDS
		 *	==============
		 *	GPopulation(gcount,gsize,p):	The default constructor of the class. It 
		 *					creates gcount genomes. Each genome's size
		 *					is set to gsize. It sets the pointer program 
		 *					to p. Every genome is randomly initialized.
		 *	getGeneration():		It returns the  consecutive number of 
		 *					the generation.
		 *	getCount():			It returns the amount of genomes in the population.
		 *	getSize():			It returns the size of each genome.
		 *	nextGeneration():		It applies the genetic operators to the 
		 *					population and it advances the generation counter.
		 *	setMutationRate(r):		It sets the value of the mutation_rate to r, if
		 *					r has value between 0 and 1.
		 *	getMutationRate():		It returns the value of the mutation_rate.
		 *	setSelectionRate(r):		It sets the value of the selection_rate  to r, if
		 *					r has value between 0 and 1.
		 *	getSelectionRate():		It returns the value of the selection_rate.
		 *	getBestFitness():		It returns the best fitness discovered so far.
		 *	evaluateBestFitness():		It evaluates the GProgram pointed by program in 
		 *					the best genome.
		 *	getTournamentSize():		It returns the size of the tournament.
		 *	setTournamemnSize(n):		It sets the tournament_size to n, if n is positive
		 *					and less than genome_count.
		 *	getBestGenome():		It returns the best genome in the population. This
		 *					genome is located in the first place of table genome,
		 *					because we use elitism.
		 *	~GPopulation():			It deallocates the memory allocated at the constructor.
		 * */
		GPopulation(int gcount,int gsize,GProgram *p);
		int	getGeneration() const;
		int	getCount() 	const;
		int	getSize() 	const;

		void	nextGeneration();
		void	setMutationRate(double r);
		void	setSelectionRate(double r);
		double	getSelectionRate() 	const;
		double	getMutationRate() 	const;
		double	getBestFitness() 	const;
		double	evaluateBestFitness();

		int	getTournamentSize()	const;
		void	setTournamentSize(int n);

		vector<int> getBestGenome() 	const;
		~GPopulation();
		
};
# define __GPOPULATION__H
# endif
