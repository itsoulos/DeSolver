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

	double kr1=0.1;
	double kr2=1.0;
	double krd=0.02;
	double kcr=0.3;
	double ka1=log(2.0)/0.75;
	double ka2=1750.0;
	double ki1=1.5;
	double ki2=0.000375;	
	double mdelay = 0.0;
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
	return 2880.0/1000.0;
}

int	getnode()
{
	return 3;
}

int	getnpoints()
{
	return 100;
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
	double f1=yy[0]-T2(x)/(1.0+ki2*O*R)+ka1*A;
	double f2=yy[1]-ka2*Adelay+k(x)*O;
	if(x<=20.0/1000.0) f2=yy[1]-ka2*0.001+k(x)*O;
	double f3=yy[2]-(kr1*O*R*O*R)/(1.0+O*R*O*R)-kcr+krd*R;
	return f1*f1+f2*f2+f3*f3;
}


void	systemder(int node, double x, double *y, double *yy,double dy,double dyy,double *res)
{
	double A=y[0];
	double O=y[1];
	double R=y[2];
	double mdelay = 20.0;
	double Adelay=A; //auto einai lathos prepei na einai A(t-Adelay)

	if(node==0)
	{
		res[0]=dyy-ka1 * dy;
		res[1]=-ka2 * dy;//edo na mpei to dy gia to delay
		res[2]=0.0;
	}
	else
	if(node==1)
	{
		double fa=T2(x)/(1.0+ki2*O*R);
		res[0]=-1.0/(fa * fa) * yy[0];	
	}
	else
	if(node==2)
	{
	}
}

void	systemf0(int node,double *f0)
{
	f0[0]=0.001;
	f0[1]=75.0;
	f0[2]=19.97;
}

}
