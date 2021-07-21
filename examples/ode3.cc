# include <math.h>
extern "C"
{

double	getx0()
{
	return 1.0;
}

double	getx1()
{
	return 2.0;
}

int	getkind()
{
	return 2;
}

int	getnpoints()
{
	return 10;
}

double	getf0()
{
	return 0.0;
}

double	getff0()
{
	return 2.0;
}

double	getf1()
{
	return 0.0;
}

double	ode1ff(double x,double y,double yy)
{
	return 0.0;
}

double	ode2ff(double x,double y,double yy,double yyy)
{
	return yyy*yy+4.0/(x*x*x);
}

}
