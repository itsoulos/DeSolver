# ifndef __GODEPROGRAM__H
# include <gprogram.h>
# include <fparser.hh>
# include <isinf.h>
# include <QLibrary>

/*	CLASS DESCRIPTION
 *	=================
 *	This class implements a GProgram, which
 *	attempts to solve Ordinary differential equations.
 * */

/*	ODE1:	ODE of first order, with the boundary condition y(x0)=f0.
 *	ODE2:	ODE of second order, with the boundary conditions y(x0)=f0
 *		and y'(x0)=ff0.
 *	ODE3:	ODE of second order, with the boundary conditions y(x0)=f0
 *		and y(x1)=f1.
 * */
# define ODE1	1
# define ODE2	2
# define ODE3	3

/*	GODE1FF:	Type definition for functions of first order equations in
 *			the form GODE1FF(x,y,y')=0.
 *	GODE2FF:	Type definition for functions of second order equations in
 *			the form GODE2FF(x,y,y',y'')=0.
 *	GFODE1FF:	Same as GODE1FF, but for fortran.
 *	GFODE2FF:	Same as GODE2FF, but for fortran.
 * */
typedef double(*GODE1FF)(double,double,double);
typedef double(*GODE2FF)(double,double,double,double);
typedef double(*GFODE1FF)(double*,double*,double*);
typedef double(*GFODE2FF)(double*,double*,double*,double*);

class GOdeProgram: public GProgram
{
	private:
		/*	PRIVATE FIELDS
		 *	==============
		 *	kind: 	The kind of the equation between ODE1, ODE2 and ODE3.
		 *	npoints:The amount of points in which we take sample for the
		 *		equation.
		 *	x0:	The left boundary of the equation.
		 *	x1:	The right boundary of the equation.
		 *	f0:	The value of y(x) on the left boundary.
		 *	f1:	The value of y(x) on the right boundary, if the kind 
		 *		of the equation is ODE3.
		 *	ff0:	The value of y'(x) on the right boundary, if the kind
		 *		of the equation is ODE2.
		 *	ode1ff: The function of the ODE, if the ODE is a first order one.
		 *	fode1ff: Same as ode1ff, but for fortran.
		 *	ode2ff: The function of the ODE, if the ODE is a second order one.
		 *	fode2ff: Same as ode2ff, but for fortran.
		 *	parser: An auxilary object of FunctionParser, for parsing and
		 *		evaluating functions and derivatives.
		 *	ptr:	An auxiliary variable.
		 * */
		int 	kind;
		int	npoints;
		double 	x0,x1;
		double 	f0,f1,ff0;
		GODE1FF ode1ff;
		GODE2FF ode2ff;
		GFODE1FF fode1ff;
		GFODE2FF fode2ff;
        QLibrary *ptr;
		FunctionParser parser;
	public:
		/*	PUBLIC FIELDS
		 *	=============
		 *	GOdeProgram(X0,X1,N):	The first constructor of the class. It sets the value of x0 to X0,
		 *				the value of x1 to X1 and the number of npoints to N. The user
		 *				must declare with other methods, the kind of the equation and the
		 *				boundary conditions.
		 *	GOdeProgram(filename):	The second constructor of the class. It loads all the necessary 
		 *				elements for the equation from the dll library filename. After that,
		 *				no other methods are necessary for setting paramaters of the ODE.
		 *	setKind(k):		It sets the kind of the equation, if the k is between ODE1 and ODE3.
		 *	setF0(f):		It sets the left boundary condition to f.
		 *	setF1(f):		It sets the right boundary condition to f, if the value of kind is ODE3.
		 *	setFF0(f):		It sets the value of derivative at x=x0, to f. This is performed if 
		 *				the value of kind is ODE2.
		 *	setOde1ff(f):		It sets the value of ode1ff to f.
		 *	setOde2ff(f):		It sets the value of ode2ff to f.
		 *	getKind():		It returns the kind of the equation.
		 *	getX0():		It returns the left boundary of the equation.
		 *	getX1():		It returns the right boundary of the equation.
		 *	getF0():		It returns the left boundary condition.
		 *	getFF0():		It returns the left derivative boundary condition.
		 *	getF1():		It returns the right boundary condition.
		 *	fitness(genome):	It evaluates the fitness of the array genome, over the 
		 *				npoints points of the equation.
		 *	~GOdeProgram():		The destructor of the class.
		 * */
		GOdeProgram(double X0,double X1,int N);
		GOdeProgram(const char *filename);

		void	setKind(int k);
		void	setF0(double f);
		void	setF1(double f);
		void	setFF0(double f);
		void	setOde1ff(GODE1FF f);
		void	setOde2ff(GODE2FF f);

		int	getKind()	const;
		double	getX0()		const;
		double	getX1()		const;
		double	getF0()		const;
		double	getF1()		const;
		double	getFF0()	const;

		virtual	double	fitness(vector<int> &genome);
		~GOdeProgram();
};

# define __GODEPROGRAM__H
# endif
