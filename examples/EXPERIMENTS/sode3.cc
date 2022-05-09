# include <math.h>
/*	This is a sample file for systems of ODE's,
 *	written in C++. The meaning of the functions is 
 *	as follows:
 *		1. getx0():  Return the left boundary of the equation.
 *		2. getx1():  Return the right boundary of the equation.
 *		3. getnode():Return the amount of the equations.
 *		4. getnpoints(): Return the number points in which the system
 *				will try to solve the ODE.
 *		5. systemfun(node,x,y,yy): Return the system of equations to 
 *				be solved. In parameter y we put the value of y's
 *				and in the table yy the value of the derivatives of y's.
 *		6. systemf0(node, f0): It returns in table f0 the left boundaries of 
 *				the equations.
 * */
extern "C"
{

double	getx0()
{
	return 0.0;
}

double	getx1()
{
	return 1.0;
}

int	getnode()
{
	return 5;
}

int	getnpoints()
{
	return 20;
}

double	systemfun(int node, double x, double *y, double *yy)
{
	double p1,p2,p3,p4,p5;
	p1=yy[0]-cos(x);//yy[0]*y[1]-(cos(x)-sin(x));
	p2=yy[1]+y[0];//yy[1]-y[0]*y[1]-exp(x)+sin(x);
        p3=yy[2]-y[1];
	p4=yy[3]+y[2];
	p5=yy[4]-y[3];
	return pow(p1,2.0)+pow(p2,2.0)+pow(p3,2.0)+pow(p4,2.0)+pow(p5,2.0);
}

void	systemf0(int node,double *f0)
{
	f0[0]=0;
	f0[1]=1;
	f0[2]=0;
	f0[3]=1;
	f0[4]=0;
}

}
