# ifndef __GPDEPROGRAM__H
# include <gprogram.h>
# include <fparser.hh>
# include <isinf.h>
# include <QLibrary>

/*	GBOUNDF:	The definition 
 * */
typedef double(*GBOUNDF)(double);
typedef double(*GFBOUNDF)(double*);
typedef double(*GPDE)(double,double,double,double, double, double ,double);
typedef double(*GFPDE)(double*,double *, double *, double *, double *,double *,double *);


/**
 * @brief The GPdeProgram class implements programs, that
 *	try to solve PDE's in R^2 with Dirichlet
 *	boundary conditions.
 */
class GPdeProgram :public GProgram
{
	private:
         /**
         * @brief x0,x1,y0,y1 The boundaries of the pde.
         */
		double x0,x1,y0,y1;
        /**
         * @brief npoints The number of training points of the pde.
         */
        int npoints;
        /**
         * @brief bpoints The number of training points of the pde,
         *			across each boundary.
         */
        int bpoints;
        /**
         * @brief f0 The boundary condition at x=x0.
         */
        GBOUNDF f0;
        /**
         * @brief f1 The boundary condition at x=x1.
         */
        GBOUNDF f1;
        /**
         * @brief g0 The boundary condition at y=y0.
         */
        GBOUNDF g0;
        /**
         * @brief g1 The boundary condition at y=y1.
         */
        GBOUNDF g1;

        /**
         * @brief ff0 The same as f0, but for the Fortran
         *			programming language.
         */
        GFBOUNDF ff0;
        /**
         * @brief ff1 The same as f1, but for the Fortran
         *			programming language.
         */
        GFBOUNDF ff1;
        /**
         * @brief fg0 The same as g0, but for the Fortran
         *			programming language.
         */
        GFBOUNDF fg0;
        /**
         * @brief fg1 The same as g1, but for the Fortran
         *			programming language.
         */
        GFBOUNDF fg1;
        /**
         * @brief pde The PDE to be solved.
         */
		GPDE pde;
        /**
         * @brief fpde The same as pde but for the Fortran
         *			programming language.
         */
		GFPDE fpde;
        /**
         * @brief parser  An auxilary object of FunctionParser, for parsing and
         *		evaluating functions and derivatives.
         */
        FunctionParser parser;
        /**
         * @brief ptr  pointer the dll containing the DE equation.
         */
        QLibrary *ptr;
	public:
        /**
         * @brief GPdeProgram 	The first constructor of the class. It sets
         *					the boundaries of the pde and the number of
         *					training points and boundary points.
         * @param X0
         * @param X1
         * @param Y0
         * @param Y1
         * @param n
         * @param b
         */
		GPdeProgram(double X0,double X1,double Y0,double Y1,int n,int b);
        /**
         * @brief GPdeProgram The second constructor of the class. It loads
         *					all the parameters of the pde from the dll
         *					named filename.
         * @param filename
         */
        GPdeProgram(QString filename);
        /**
         * @brief getX0
         * @return the left boundary on xx'.
         */
		double	getX0() const;
        /**
         * @brief getX1
         * @return the right boundary on xx'.
         */
		double  getX1() const;
        /**
         * @brief getY0
         * @return  the left boundary on yy'.
         */
		double  getY0() const;
        /**
         * @brief getY1
         * @return the right boundary on yy'.
         */
		double	getY1() const;
        /**
         * @brief getNpoints the number of training points.
         * @return
         */
		double  getNpoints() const;
        /**
         * @brief getBoundaryPoints
         * @return the number of boundary points.
         */
		double  getBoundaryPoints() const;
        /**
         * @brief setBoundaries 	It sets the boundary conditions.
         * @param F0
         * @param F1
         * @param G0
         * @param G1
         */
		void	setBoundaries(GBOUNDF F0,GBOUNDF F1,GBOUNDF G0,GBOUNDF G1);
        /**
         * @brief setPde It sets the PDE.
         * @param p
         */
		void	setPde(GPDE p);
        /**
         * @brief fitness
         * @param genome
         * @return  the fitness value for the integer
         *					array genome.
         */
		virtual double fitness(vector<int> &genome);	
		~GPdeProgram();
};

# define __GPDEPROGRAM__H
# endif
