# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <get_options.h>
# include <QString>
# include <QStringList>
# include <QDebug>
const char *short_options="hp:c:k:l:r:g:e:s:m:";

void print_usage()
{
    printf("\t--help        Display this usage information.\n"
           "\t--kind=DE_KIND     Speciy equation kind (ode,pde,sode) Default ode.\n"
            "\t--problem=<file>	 Specify dll with the equation. Default ()\n"
            "\t--count=<i>    Specify population count. Default 1000.\n"
            "\t--length=<i>	 Specify each genome's length. Default 50.\n"
            "\t--random=<i>	 Specify seed for random generator. Default 1.\n"
            "\t--generations=<i>	 Specify maximum number of generations. Default 2000.\n"
            "\t--epsilon=<f>	 Specify threshold for termination. Default 1e-7\n"
            "\t--srate=<f>	 Specify selection rate. Default 0.1\n"
            "\t--threads=<i> Specify the number of OpenMP threads. Default 1.\n"
            "\t--mrate=<f>	 Specify mutation rate. Default 0.05\n");
}

QString	dll_name="";
QString ode_kind="ode";
int     chromosome_count=1000;
int     chromosome_size=50;
int     genome_rand=1;
int     maxgenerations=2000;
double  eps=1e-7;
double  mutation_rate=0.1;
double  selection_rate=0.05;
int threads=1;

void parseCmdLine(QStringList args)
{
    for(int i=1;i<args.size();i++)
    {
        if(args[i]=="--help")
        {
            print_usage();
            exit(EXIT_SUCCESS);
        }
        QStringList sp=args[i].split("=");
        QString param=sp[0];
        QString value=sp[1];
        if(param=="--kind")
        {
            ode_kind=value;
        }
        else
        if(param=="--problem")
        {
            if(!value.startsWith(".") && !value.startsWith("/")) value="./"+value;
            dll_name=value;
        }
        else
        if(param=="--count")
        {
            chromosome_count=value.toInt();
        }
        else
        if(param=="--length")
        {
            chromosome_size=value.toInt();
        }
        else
        if(param=="--random")
        {
            genome_rand=value.toInt();
        }
        else
        if(param=="--generations")
        {
            maxgenerations=value.toInt();
        }
        else
        if(param=="--epsilon")
        {
            eps=value.toDouble();
        }
        else
        if(param=="--srate")
        {
            selection_rate=value.toDouble();
        }
        else
        if(param=="--mrate")
        {
            mutation_rate=value.toDouble();
        }
        else
        if(param=="--threads")
        {
            threads = value.toInt();
        }
    }
}

/*
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

*/
