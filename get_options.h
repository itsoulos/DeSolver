# ifndef __GETOPTIONS__H

extern void print_usage();
extern char	dll_name[1024];
extern  char ode_kind[100];
extern int     genome_count;
extern int     genome_size;
extern int     genome_rand;
extern int     maxgenerations;
extern double  eps;
extern double  mutation_rate;
extern double  selection_rate;
extern void	get_options(int argc,char **argv);

# define __GETOPTIONS__H
# endif
