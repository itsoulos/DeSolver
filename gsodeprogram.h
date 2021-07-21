# ifndef __GSODEPROGRAM__H
# include <gprogram.h>
# include <fparser.hh>
# include <vector>
# include <string>
# include <isinf.h>
# include <QString>
# include <QLibrary>
using namespace std;

/*	CLASS DESCRIPTION
 *	=================
 *	The class represents programs based on GProgram, that trie
 *	to solve systems of ODE's. Every ode is first order and it
 *	has left boundary conditions.
 * */

/*	GSYSTEMFUN:	Function which represent the system of ODE's. The first
 *			argument is the number of the equations, the second is 
 *			the point at which we want to evaluate the system, the third
 *			argument is a table that holds the value of y's and the last
 *			parameter is a table that holds the value of derivatives of y's.
 *	GFSYSTEMFUN:	The same as above, but for the Fortran programming language.
 *	GSYSTEMF0:	Represents the boundary conditions for every ode in the system. The
 *			first parameter is the number of the ODE's and the second is a table
 *			that holds the values of y's at x=x0.
 *	GFSYSTEMF0:	The same as above, but for the Fortran programming language.
 * */
typedef double(*GSYSTEMFUN)(int ,double, double *,double *);
typedef double(*GFSYSTEMFUN)(int *,double *,double *,double *);
typedef void(*GSYSTEMF0)(int,double *);
typedef int(*GFSYSTEMF0)(int *,double *);
typedef void(*SETPARAM)(QString,QString);

class GSodeProgram :public GProgram
{
	private:
		/*	PRIVATE FIELDS
		 *	=================
		 *	node:	The number of equations in the system.
		 *	x0:	The left boundary of the system.
		 *	x1:	The right boundary of the system.
		 *	npoints: The number of points at which  the solution will be obtained.
		 *	f0:	An array that holds the left boundary conditions.
		 *	ptr:	An auxiliary variable.
		 *	parser:	A vector keeping the FunctionParsers of the system.
		 *	systemfun:  The system of the equations.
		 *	fsystemfun: The system of the equations in the Fortran programming language.
		 *	systemf0:   The left boundary conditions as a function.
		 *	fsystemf0:  The left boundary conditions as a function, in
		 *		    the Fortran programming language.
		 * */
		int 	node;
		double 	x0,x1;
		int 	npoints;
        double 	*f0;
        QLibrary *ptr;
		vector<FunctionParser*> parser;
		GSYSTEMFUN 	systemfun;
		GFSYSTEMFUN 	fsystemfun;
		GSYSTEMF0   	systemf0;
		GFSYSTEMF0  	fsystemf0;
		SETPARAM	setparam;
	public:
		/*	PUBLIC FIELDS
		 *	===============
		 *	GSodeProgram(X0,X1,Node,Npoints): The first constructor of the system. It sets
		 *					  the x0 to X0, x1 to X1, node to Node and npoints
		 *					  to Npoints. 
		 *	GSodeProgram(filename):		  The second constructor of the system. It uses
		 *					  the dll stored in filename to initialize the system
		 *					  of ODE's. After that, no other method is required 
		 *					  for initialization of the system.
		 *	setGsystemFun(f):		  It sets the value of gsystemfun to f.
		 *	setGsystemF0(f):		  It sets the value of gsystemf0 to f.
		 *	getX0():			  It returns the left boundary.
		 *	getX1():			  It returns the right boundary.
		 *	getNode():			  It returns the amount of ODE's.
		 *	getNpoints():			  It returns the amount of the training points.
		 *	getF0(f):			  It returns in f the boundary conditions.
		 *	fitness(genome):		  It returns the fitness value asscociated with
		 *					  the integer array genome.
		 *	~GSodeProgram():		  The destructor of the class.
		 * */
		GSodeProgram(double X0,double X1,int Node,int Npoints);
		GSodeProgram(const char *filename);
		double	getX0() const;
		double	getX1() const;
		int	getNode() const;
		int	getNpoints() const;
		void	getF0(double *f) const;
		void	setGsystemFun(GSYSTEMFUN f);
		void	setGsystemF0(GSYSTEMF0 f);
		virtual double fitness(vector<int> &genome);
		~GSodeProgram();
};

# define __GSODEPROGRAM__H
# endif
