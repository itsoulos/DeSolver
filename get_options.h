# ifndef __GETOPTIONS__H
# include <QString>
# include <QStringList>

/**
 * @brief print_usage. The method displays the usage informations
 *    and terminates.
 */
extern void print_usage();

/**
 * @brief dll_name The path of the differential equation to be solved.
 */
extern QString	dll_name;
/**
 * @brief ode_kind The kind of differential equation to be solved. Accepted values are:
 *    ode, sode, pde
 */
extern QString ode_kind;
/**
 * @brief chromosome_count The number of chromosomes in the genetic population.
 */
extern int     chromosome_count;
/**
 * @brief chromosome_size The size of the chromosomes.
 */
extern int     chromosome_size;
/**
 * @brief genome_rand The seed for the random number generation
 */
extern int     genome_rand;
/**
 * @brief maxgenerations The maximum number of generations allowed.
 */
extern int     maxgenerations;
/**
 * @brief eps A small positive number used in double numbers comparisons.
 */
extern double  eps;
/**
 * @brief mutation_rate The mutation rate used in the genetic algorithm.
 */
extern double  mutation_rate;
/**
 * @brief selection_rate
 */
extern double  selection_rate;

/**
 * @brief parseCmdLine This method parses the command line.
 * @param args The arguments of the command line.
 */
void parseCmdLine(QStringList args);

# define __GETOPTIONS__H
# endif
