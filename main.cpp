# include <get_options.h>
#include <iostream>
# include <godeprogram.h>
# include <gpopulation.h>
# include <gsodeprogram.h>
# include <gpdeprogram.h>
# include <ode_grammar.h>
# include <pde_grammar.h>
# include <math.h>
# include <get_options.h>
# include <stdio.h>
# include <QCoreApplication>

using namespace std;
GOdeProgram     *ode_program=NULL;
GPopulation     *ode_population=NULL;
OdeGrammar      *ode_grammar=NULL;
PdeGrammar      *pde_grammar=NULL;
GPdeProgram     *pde_program   =NULL;
GPopulation     *pde_population=NULL;
GSodeProgram    *sode_program   =NULL;
GPopulation     *sode_population=NULL;


vector<GProgram*> ompODeProgram;

void init_ode()
{
    ode_grammar=new OdeGrammar;
    ode_program =new GOdeProgram(dll_name);
    ode_program->setStartSymbol(ode_grammar->getStartSymbol());

    ompODeProgram.resize(threads);
    for(int i=0;i<threads;i++)
    {
        ompODeProgram[i]=new GOdeProgram(dll_name);
        ompODeProgram[i]->setStartSymbol(ode_grammar->getStartSymbol());
    }
    if(threads<=1)
        ode_population=new GPopulation(chromosome_count,chromosome_size,ode_program);
    else
    ode_population=new GPopulation(chromosome_count,chromosome_size,ompODeProgram);
    ode_population->setSelectionRate(selection_rate);
    ode_population->setMutationRate(mutation_rate);
}

void    run_ode()
{
    int iters=0;
    vector<int> genome;
    genome.resize(chromosome_size);
    string solution;
    int redo;
    double fitness;
    for(iters=1;iters<=maxgenerations;iters++)
    {
        ode_population->nextGeneration();
        genome=ode_population->getBestGenome();
        fitness=ode_population->getBestFitness();
        redo=0;
        solution=ode_program->printProgram(genome,redo);
        printf("GENERATION: %4d\t FITNESS: %.10lg \t SOLUTION: %s\n",
                iters,fabs(fitness),solution.c_str());
        if(fabs(fitness)<eps) break;
      }
}

void    done_ode()
{
    for(int i=0;i<threads;i++)
        delete ompODeProgram[i];

    delete ode_program;
    delete ode_population;
    delete ode_grammar;
}

void    init_pde()
{
    pde_grammar=new PdeGrammar;
    pde_program =new GPdeProgram(dll_name);
    pde_program->setStartSymbol(pde_grammar->getStartSymbol());
    ompODeProgram.resize(threads);

    for(int i=0;i<threads;i++)
    {
        ompODeProgram[i]=new GPdeProgram(dll_name);
        ompODeProgram[i]->setStartSymbol(pde_grammar->getStartSymbol());
    }
    if(threads<=1)
        pde_population=new GPopulation(chromosome_count,chromosome_size,pde_program);
    else
    pde_population=new GPopulation(chromosome_count,chromosome_size,ompODeProgram);
    pde_population->setSelectionRate(selection_rate);
    pde_population->setMutationRate(mutation_rate);
}

void    run_pde()
{
    int iters=0;
    vector<int> genome;
    genome.resize(chromosome_size);
    string solution;
    int redo;
    double fitness;
    for(iters=1;iters<=maxgenerations;iters++)
    {
        pde_population->nextGeneration();
        genome=pde_population->getBestGenome();
        fitness=pde_population->getBestFitness();
        redo=0;
        solution=pde_program->printProgram(genome,redo);
        printf("GENERATION: %4d\t FITNESS: %.10lg \t SOLUTION: %s\n",iters,
               fabs(fitness),solution.c_str());
        if(fabs(fitness)<eps) break;
     }
}

void    done_pde()
{
    for(int i=0;i<threads;i++)
        delete ompODeProgram[i];
    delete pde_population;
    delete pde_program;
    delete pde_grammar;
}

void    init_sode()
{
    ode_grammar=new OdeGrammar;
    sode_program =new GSodeProgram(dll_name);
    sode_program->setStartSymbol(ode_grammar->getStartSymbol());
    ompODeProgram.resize(threads);

    for(int i=0;i<threads;i++)
    {
        ompODeProgram[i]=new GSodeProgram(dll_name);
        ompODeProgram[i]->setStartSymbol(ode_grammar->getStartSymbol());
    }
    if(threads<=1)
        sode_population=new GPopulation(chromosome_count,chromosome_size,sode_program);
    else
    sode_population=new GPopulation(chromosome_count,chromosome_size,ompODeProgram);
    sode_population->setSelectionRate(selection_rate);
    sode_population->setMutationRate(mutation_rate);
}

void    run_sode()
{

    int iters=0,i,j;
    vector<int> genome;
    genome.resize(chromosome_size);

    vector<int> part;
    part.resize(chromosome_size/sode_program->getNode());
    vector<string> solution;
    solution.resize(sode_program->getNode());
    int redo;
    double fitness;

    for(iters=1;iters<=maxgenerations;iters++)
    {
            sode_population->nextGeneration();
            genome=sode_population->getBestGenome();
            fitness=sode_population->getBestFitness();
            for(i=0;i<sode_program->getNode();i++)
            {
                    redo=0;
                    for(j=0;j<chromosome_size/sode_program->getNode();j++)
                            part[j]=genome[i*(chromosome_size/sode_program->getNode())+j];
                    solution[i]=sode_program->printProgram(part,redo);
            }
            printf("GENERATION: %4d\t FITNESS: %.10lg \n",iters,fabs(fitness));
            printf("SOLUTIONS:\n");
            for(i=0;i<sode_program->getNode();i++)
                    printf("f%d(x)= %s\n",i+1, solution[i].c_str());
            if(fabs(fitness)<eps) break;
    }

}

void    done_sode()
{
    for(int i=0;i<threads;i++)
        delete ompODeProgram[i];
    delete ode_grammar;
    delete sode_population;
    delete sode_program;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc,argv);
     setlocale(LC_ALL,"C");
    parseCmdLine(app.arguments());
    srand(genome_rand);
    if(dll_name=="")
    {
        print_usage();
        return 0;
    }
    if(ode_kind=="ode")
    {
        init_ode();
        run_ode();
        done_ode();
    }
    else
    if(ode_kind=="pde")
    {
        init_pde();
        run_pde();
        done_pde();
    }
    else
    if(ode_kind=="sode")
    {
        init_sode();
        run_sode();
        done_sode();
    }
    return 0;
}
