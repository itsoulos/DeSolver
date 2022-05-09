# ifndef __GSODEPROGRAM__H
# include <gprogram.h>
# include <fparser.hh>
# include <vector>
# include <string>
# include <isinf.h>
# include <QString>
# include <QLibrary>
using namespace std;


/**
 * @brief	GSYSTEMFUN:	Function which represent the system of ODE's. The first
 *			argument is the number of the equations, the second is 
 *			the point at which we want to evaluate the system, the third
 *			argument is a table that holds the value of y's and the last
 *			parameter is a table that holds the value of derivatives of y's.
 *	@brief GFSYSTEMFUN:	The same as above, but for the Fortran programming language.
 *	@brief GSYSTEMF0:	Represents the boundary conditions for every ode in the system. The
 *			first parameter is the number of the ODE's and the second is a table
 *			that holds the values of y's at x=x0.
 *	@brief GFSYSTEMF0:	The same as above, but for the Fortran programming language.
 * */
typedef double(*GSYSTEMFUN)(int ,double, double *,double *);
typedef double(*GFSYSTEMFUN)(int *,double *,double *,double *);
typedef void(*GSYSTEMF0)(int,double *);
typedef int(*GFSYSTEMF0)(int *,double *);
typedef void(*SETPARAM)(QString,QString);

/**
 * @brief The GSodeProgram class  represents programs based on GProgram, that trie
 *	to solve systems of ODE's. Every ode is first order and it
 *	has left boundary conditions.
 */
class GSodeProgram :public GProgram
{
	private:
        /**
         * @brief node The number of equations in the system.
         */
		int 	node;
        /**
         * @brief x0 	The left boundary of the system.
         */
        double 	x0;
        /**
         * @brief x1 The right boundary of the system.
         */
        double x1;
        /**
         * @brief npoints The number of points at which  the solution will be obtained.
         */
		int 	npoints;
        /**
         * @brief f0 An array that holds the left boundary conditions.
         */
        double 	*f0;
        /**
         * @brief ptr An auxiliary variable.
         */
        QLibrary *ptr;
        /**
         * @brief parser 	A vector keeping the FunctionParsers of the system.
         */
		vector<FunctionParser*> parser;
        /**
         * @brief systemfun  The system of the equations.
         */
		GSYSTEMFUN 	systemfun;
        /**
         * @brief fsystemfun  The system of the equations in the Fortran programming language.
         */
		GFSYSTEMFUN 	fsystemfun;
        /**
         * @brief systemf0  The left boundary conditions as a function.
         */
		GSYSTEMF0   	systemf0;
        /**
         * @brief fsystemf0 The left boundary conditions as a function, in
         *		    the Fortran programming language.
         */
		GFSYSTEMF0  	fsystemf0;
		SETPARAM	setparam;
	public:
        /**
         * @brief GSodeProgram The first constructor of the system. It sets
         *					  the x0 to X0, x1 to X1, node to Node and npoints
         *					  to Npoints.
         * @param X0
         * @param X1
         * @param Node
         * @param Npoints
         */
		GSodeProgram(double X0,double X1,int Node,int Npoints);
        /**
         * @brief GSodeProgram   The second constructor of the system. It uses
         *					  the dll stored in filename to initialize the system
         *					  of ODE's. After that, no other method is required
         *					  for initialization of the system.
         * @param filename
         */
        GSodeProgram(QString filename);
        /**
         * @brief getX0
         * @return  the left boundary.
         */
		double	getX0() const;
        /**
         * @brief getX1
         * @return the right boundary.
         */
		double	getX1() const;
        /**
         * @brief getNode
         * @return the number of ODE's.
         */
		int	getNode() const;
        /**
         * @brief getNpoints
         * @return the number of the training points.
         */
		int	getNpoints() const;
        /**
         * @brief getF0 returns in f the boundary conditions
         * @param f
         */
		void	getF0(double *f) const;
        /**
         * @brief setGsystemFun sets the value of gsystemfun to f.
         * @param f
         */
		void	setGsystemFun(GSYSTEMFUN f);
        /**
         * @brief setGsystemF0 sets the value of gsystemf0 to f.
         * @param f
         */
		void	setGsystemF0(GSYSTEMF0 f);
        /**
         * @brief fitness the fitness value asscociated with
         *					  the integer array genome.
         * @param genome
         * @return
         */
		virtual double fitness(vector<int> &genome);
		~GSodeProgram();
};

# define __GSODEPROGRAM__H
# endif
