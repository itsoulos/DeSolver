# ifndef __GETOPTIONS__H
# include <QString>
# include <QStringList>

extern void print_usage();
extern QString	dll_name;
extern QString ode_kind;
extern int     chromosome_count;
extern int     chromosome_size;
extern int     genome_rand;
extern int     maxgenerations;
extern double  eps;
extern double  mutation_rate;
extern double  selection_rate;

void parseCmdLine(QStringList args);

# define __GETOPTIONS__H
# endif
