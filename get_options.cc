# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

const char *short_options="hp:c:k:l:r:g:e:s:m:";

void print_usage()
{
    printf("\t-h	 Display this usage information.\n"
           "\t-k     Speciy equation kind (ode,pde,sode) Default ode.\n"
            "\t-p	 Specify dll with the equation. Default ()\n"
            "\t-c    Specify population count. Default 1000.\n"
            "\t-l	 Specify each genome's length. Default 50.\n"
            "\t-r	 Specify seed for random generator. Default 1.\n"
            "\t-g	 Specify maximum number of generations. Default 2000.\n"
            "\t-e	 Specify threshold for termination. Default 1e-7\n"
            "\t-s	 Specify selection rate. Default 0.1\n"
            "\t-m	 Specify mutation rate. Default 0.05\n");
}

char    ode_kind[100];
char	dll_name[1024];
int     genome_count=1000;
int     genome_size=50;
int     genome_rand=1;
int     maxgenerations=2000;
double  eps=1e-7;
double  mutation_rate=0.05;
double  selection_rate=0.1;

void	get_options(int argc,char **argv)
{
	if(argc==1)
	{
		print_usage();
		exit(0);
	}
    strcpy(ode_kind,"ode");//ode-pde-sode
	int next_option;
	char count_string[100];
	strcpy(count_string,"1000");
	char length_string[100];
	strcpy(length_string,"50");
	char random_string[100];
	strcpy(random_string,"1000");
	char generations_string[100];
	strcpy(generations_string,"2000");
	char eps_string[100];
	strcpy(eps_string,"0.0000001");
	char selection_string[100];
	strcpy(selection_string,"0.1");
	char mutation_string[100];
	strcpy(mutation_string,"0.05");
	do
	{
		next_option=getopt(argc,argv,short_options);
		switch(next_option)
		{
			case 'h':
				print_usage();
				exit(0);
				break;
            case 'k':
                strcpy(ode_kind,optarg);
            break;
			case 'p':
				strcpy(dll_name,optarg);
				break;
			case 'c':
				strcpy(count_string,optarg);
				break;
			case 'l':
				strcpy(length_string,optarg);
				break;
			case 'r':
				strcpy(random_string,optarg);
				break;
			case 'g':
				strcpy(generations_string,optarg);
				break;
			case 'e':
				strcpy(eps_string,optarg);
				break;
			case 's':
				strcpy(selection_string,optarg);
				break;
			case 'm':
				strcpy(mutation_string,optarg);
				break;
			case -1:
				break;
			case '?':
				print_usage();
				exit(1);
				break;
			default:
				print_usage();
				exit(1);
				break;
		}
	}while(next_option!=-1);
	genome_count=atoi(count_string);
	genome_size=atoi(length_string);
	genome_rand=atoi(random_string);
	maxgenerations=atoi(generations_string);
	eps=atof(eps_string);
	selection_rate=atof(selection_string);
	mutation_rate=atof(mutation_string);
}

