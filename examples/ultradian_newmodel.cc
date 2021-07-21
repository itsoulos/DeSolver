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

double h1=10000;
double h2=1000;
double mdelay =0.0;
double S1=8000/h1;
double k_i1=80;
double k_i2=0.8;
double k_i3=0.8;
double l=290;
double k_e1=log(2)/0.75;
double k_e2=3600;
double k_r1=0.1;
double k_r2=4800;
double k_cr=0.35;
double k_rd=0.02;
double k_A1=log(2)/0.75;
double k_A2=0.04;
double k_o=60;
double k_c1=log(2)/0.75;
double k_c2=20;
double delay2=0.0;
double delay3=0.0;

void setparam(QString key,QString value)
{
	if(key == "delay") 
		mdelay = value.toDouble();
    else
    if(key=="delay2")
        delay2=value.toDouble();
    else
    if(key=="delay3")
        delay3=value.toDouble();
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
    return 6;
}

int	getnpoints()
{
    return 1000;
}

double k(double t)
{
    return log(2.0)/8.0;
}

double T2(double t)
{
    double pi=M_PI;
    return ((150+(60*(sin(32*pi*t/l)+0.85*sin(20*pi*t/l)+0.70*sin(12*t*pi/l)+0.5*sin(9*t*pi/l)+0*sin(3*t*pi/l)+0.25*sin(5*t*pi/l)+0*sin(t*pi/l))))/h1);
}

double T1(double t)
{
    double pi=M_PI;
    return (500*pow(sin((t*pi)/(1440)),2)*(pow(sin(pi*t/20),2))+0.75)/h2;
}
double systemfun(int node, double x, double *y, double *yy)
{
/** A(t),O(t),R(t)*/

    double f1=yy[0]-(T1(x)/(1+y[4-1]*y[5-1]*k_i3)-k_c1*y[1-1]);
    double f2=yy[1]-((S1+k_c2*y[1-1])/(1+y[4-1]*y[5-1]*k_i2)-k_A1*y[2-1]);
    double f3=yy[2]-((T2(x)+k_A2*y[2-1])/(1+y[4-1]*y[5-1]*k_i1)-k_e1*y[3-1]);
    double f4=yy[3]-(k_e2*delay3-k(x)*y[4-1]);
    double f5=yy[4]-(k_r1*pow((y[4-1]*y[5-1]),2)/(k_r2+(pow(y[4-1]*y[5-1],2))+k_cr-k_rd*y[5-1]));
    double f6=yy[5]-(k_o*delay2-k(x)*y[6-1]);
    return f1*f1+f2*f2+f3*f3+f4*f4+f5*f5+f6*f6;
}


void	systemder(int node, double x, double *y, double *yy,double dy,double dyy,double *res)
{
}

void	systemf0(int node,double *f0)
{
//edo einai t=0
    f0[0]=0.01;
    f0[1]=0.1;
    f0[2]=0.00001;
    f0[3]=1.5;
    f0[4]=17.6;
    f0[5]=50.0;
}

}
