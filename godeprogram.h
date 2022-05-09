# ifndef __GODEPROGRAM__H
# include <gprogram.h>
# include <fparser.hh>
# include <isinf.h>
# include <QLibrary>

/**
 * @brief ODE1: ODE of first order, with the boundary condition y(x0)=f0.
 * @brief ODE2: ODE of second order, with the boundary conditions y(x0)=f0
 *		and y'(x0)=ff0.
 * @brief ODE3: ODE of second order, with the boundary conditions y(x0)=f0
 *		and y(x1)=f1.
 */
# define ODE1	1
# define ODE2	2
# define ODE3	3

/**
 *
 * @brief GODE1FF:	Type definition for functions of first order equations in
 *			the form GODE1FF(x,y,y')=0.
 * @brief	GODE2FF:	Type definition for functions of second order equations in
 *			the form GODE2FF(x,y,y',y'')=0.
 * @brief	GFODE1FF:	Same as GODE1FF, but for fortran.
 * @brief	GFODE2FF:	Same as GODE2FF, but for fortran.
 * */

typedef double(*GODE1FF)(double,double,double);
typedef double(*GODE2FF)(double,double,double,double);
typedef double(*GFODE1FF)(double*,double*,double*);
typedef double(*GFODE2FF)(double*,double*,double*,double*);

/**
 * @brief The GOdeProgram class implements a GProgram, which
 *	attempts to solve Ordinary differential equations.
 */
class GOdeProgram: public GProgram
{
	private:
        /**
         * @brief kind The kind of the equation between ODE1, ODE2 and ODE3.
         */
		int 	kind;
        /**
         * @brief npoints The number of points in which we take sample for the
         *		equation.
         */
		int	npoints;
        /**
         * @brief x0 The left boundary of the equation.
         */
        double 	x0;
        /**
         * @brief x1 	The right boundary of the equation.
         */
        double x1;
        /**
         * @brief f0 The value of y(x) on the left boundary.
         */
        double 	f0;
        /**
         * @brief f1 The value of y(x) on the right boundary, if the kind
         *		of the equation is ODE3.
         */
        double f1;
        /**
         * @brief ff0 The value of y'(x) on the right boundary, if the kind
         *		of the equation is ODE2.
         */
        double ff0;
        /**
         * @brief ode1ff The function of the ODE, if the ODE is a first order one.
         */
		GODE1FF ode1ff;
        /**
         * @brief ode2ff The function of the ODE, if the ODE is a second order one.
         */
		GODE2FF ode2ff;
        /**
         * @brief fode1ff Same as ode1ff, but for fortran.
         */
		GFODE1FF fode1ff;
        /**
         * @brief fode2ff Same as ode2ff, but for fortran.
         */
		GFODE2FF fode2ff;
        /**
         * @brief ptr pointer the dll containing the DE equation.
         */
        QLibrary *ptr;
        /**
         * @brief parser An auxilary object of FunctionParser, for parsing and
         *		evaluating functions and derivatives.
         */
		FunctionParser parser;
	public:
        /**
         * @brief GOdeProgram The first constructor of the class. It sets the value of x0 to X0,
         *				the value of x1 to X1 and the number of npoints to N. The user
         *				must declare with other methods, the kind of the equation and the
         *				boundary conditions.
         * @param X0
         * @param X1
         * @param N
         */
		GOdeProgram(double X0,double X1,int N);
        /**
         * @brief GOdeProgram The second constructor of the class. It loads all the necessary
         *				elements for the equation from the dll library filename. After that,
         *				no other methods are necessary for setting paramaters of the ODE.
         * @param filename
         */
        GOdeProgram(QString filename);

        /**
         * @brief setKind It sets the kind of the equation, if the k is between ODE1 and ODE3.
         * @param k
         */
		void	setKind(int k);
        /**
         * @brief setF0 It sets the left boundary condition to f.
         * @param f
         */
		void	setF0(double f);
        /**
         * @brief setF1 	It sets the right boundary condition to f, if the value of kind is ODE3.
         * @param f
         */
		void	setF1(double f);
        /**
         * @brief setFF0 It sets the value of derivative at x=x0, to f. This is performed if
         *				the value of kind is ODE2.
         * @param f
         */
		void	setFF0(double f);
        /**
         * @brief setOde1ff It sets the value of ode1ff to f.
         * @param f
         */
		void	setOde1ff(GODE1FF f);
        /**
         * @brief setOde2ff It sets the value of ode2ff to f.
         * @param f
         */
		void	setOde2ff(GODE2FF f);

        /**
         * @brief getKind
         * @return the kind of the equation.
         */
		int	getKind()	const;
        /**
         * @brief getX0
         * @return  the left boundary of the equation.
         */
		double	getX0()		const;
        /**
         * @brief getX1 the right boundary of the equation.
         * @return
         */
		double	getX1()		const;
        /**
         * @brief getF0 the left boundary condition.
         * @return
         */
		double	getF0()		const;
        /**
         * @brief getF1
         * @return the right boundary condition.
         */
		double	getF1()		const;
        /**
         * @brief getFF0
         * @return left derivative boundary condition.
         */
		double	getFF0()	const;

        /**
         * @brief fitness It evaluates the fitness of the array genome, over the
         *				npoints points of the equation.
         * @param genome
         * @return
         */
		virtual	double	fitness(vector<int> &genome);
		~GOdeProgram();
};

# define __GODEPROGRAM__H
# endif
