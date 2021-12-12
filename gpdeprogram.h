# ifndef __GPDEPROGRAM__H
# include <gprogram.h>
# include <fparser.hh>
# include <isinf.h>
# include <QLibrary>
/*	CLASS DESCRIPTION
 *	=================
 *	This class implements programs, that
 *	try to solve PDE's in R^2 with Dirichlet 
 *	boundary conditions.
 * */

/*	GBOUNDF:	The definition 
 * */
typedef double(*GBOUNDF)(double);
typedef double(*GFBOUNDF)(double*);
typedef double(*GPDE)(double,double,double,double, double, double ,double);
typedef double(*GFPDE)(double*,double *, double *, double *, double *,double *,double *);

class GPdeProgram :public GProgram
{
	private:
		/*	PRIVATE FIELDS
		 *	==============
		 *	x0,x1,y0,y1:	The boundaries of the pde.
		 *	npoints:	The amount of training points of the pde.
		 *	bpoints:	The amount of training points of the pde, 
		 *			across each boundary.
		 *	f0:		The boundary condition at x=x0.
		 *	ff0:		The same as above, but for the Fortran 
		 *			programming language.
		 *	f1:		The boundary condition at x=x1.
		 *	ff1:		The same as above, but for the Fortran
		 *			programming language.
		 *	g0:		The boundary condition at y=y0.
		 *	fg0:		The same as above, but for the Fortran
		 *			programming language.
		 *	g1:		The boundary condition at y=y1.
		 *	fg1:		The same as above, but for the Fortran 
		 *			programming language.
		 *	pde:		The PDE to be solved.
		 *	fpde:		The same as above but for the Fortran
		 *			programming language.
		 *	parser:		Auxiliary parser variable.
		 *	ptr:		Auxiliary variable.
		 * */
		double x0,x1,y0,y1;
		int npoints, bpoints;
		GBOUNDF f0, f1, g0, g1;
		GFBOUNDF ff0,ff1,fg0,fg1;
		GPDE pde;
		GFPDE fpde;
        FunctionParser parser;
        QLibrary *ptr;
	public:
		/*	PUBLIC FIELDS
		 *	=============
		 *	GPdeProgram(X0,X1,Y0,Y1,n,b):	The first constructor of the class. It sets
		 *					the boundaries of the pde and the number of 
		 *					training points and boundary points.
		 *	GPdeProgram(filename):		The second constructor of the class. It loads
		 *					all the parameters of the pde from the dll 
		 *					named filename.
		 *	getX0():			It returns the left boundary on xx'.
		 *	getX1():			It returns the right boundary on xx'.
		 *	getY0():			It returns the left boundary on yy'.
		 *	getY1():			It returns the right boundary on yy'.
		 *	getNpoints():			It returns the amount of training points.
		 *	getBoundaryPoints():		It returns the amount of boundary points.
		 *	setBoundaries(F0,F1,G0,G1):	It sets the boundary conditions.
		 *	setPde(p):			It sets the PDE.
		 *	fitness(genome):		It returns the fitness value for the integer
		 *					array genome.
		 *	~GPdeProgram():			The destructor of the class.
		 * */
		GPdeProgram(double X0,double X1,double Y0,double Y1,int n,int b);
        GPdeProgram(QString filename);
		double	getX0() const;
		double  getX1() const;
		double  getY0() const;
		double	getY1() const;
		double  getNpoints() const;
		double  getBoundaryPoints() const;
		void	setBoundaries(GBOUNDF F0,GBOUNDF F1,GBOUNDF G0,GBOUNDF G1);
		void	setPde(GPDE p);
		virtual double fitness(vector<int> &genome);	
		~GPdeProgram();
};

# define __GPDEPROGRAM__H
# endif
