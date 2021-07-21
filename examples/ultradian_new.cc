# include <math.h>
# include <stdio.h>
# include <QString>
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


/** Constants of the equation **/

	double mdelay = 0.0;
	double k_c1=log(2.0)/0.75;
	double k_c2=10000;
	double k_a2=3000;
	double k_i1=2.0;
	double k_i2=2.0;
	double k_r1=0.1;
	double k_r2=1.0;
	double C=1.0;
	double k_cr=0.3;
	double k_rd=0.02;
	double k1=log(2.0)/10.0;
	double k_oa=log(2.0)/0.75;
	
void setparam(QString key,QString value)
{
	if(key == "delay") 
		mdelay = value.toDouble();
}

double	getx0()
{
	return 0.0;
}

double	getx1()
{
	return 1440;
}

int	getnode()
{
	return 3;
}

int	getnpoints()
{
	return 200;
}

double k(double t)
{
	return log(2.0)/2.0;
}

double T2(double t)
{
	double pi=M_PI;
	double h1=10000;
	double h2=2000;
	return (160+(32*(sin(t*pi/12.5)+sin(t*pi/25)+sin(t*pi/60)+sin(t*pi/110)+sin(t*pi/220))))/h1;
}

double systemfun(int node, double x, double *y, double *yy)
{
/** A(t),O(t),R(t)*/
	double A=y[0];
	double O=y[1];
	double R=y[2];
	double Adelay=mdelay;
	if(x<20) Adelay = 0.002;

	double pi=M_PI;
	double k_a1=40+8*(sin(x*pi/15)+sin(x*pi/30)+sin(x*pi/60)+sin(x*pi/120)+sin(x*pi/240)+sin(x*pi/480));
	k_a1=40+8*(sin(x*pi/15)+sin(x*pi/30)+sin(x*pi/60)+sin(x*pi/120)+sin(x*pi/240)+sin(x*pi/480));

	double f1=yy[0]-(k_a1/(1+O*R*10)-k_oa*A);
	double f2=yy[1]-(k_a2*Adelay-k(x)*O);
	double f3=yy[2]-((k_r1*O*O*R*R/(k_r2+O*R*O*R)+k_cr-k_rd*R));
	return f1*f1+f2*f2+f3*f3;
}


void	systemder(int node, double x, double *y, double *yy,double dy,double dyy,double *res)
{
}

void	systemf0(int node,double *f0)
{
//edo einai t=0
	f0[0]=0.002;
	f0[1]=50.0;
	f0[2]=19.97;
}

}
