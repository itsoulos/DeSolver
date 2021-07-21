# ifdef __SOLARIS__
# include <math.h>
int isinf(double x)
{
	return fabs(x)>1e+10;
}
# endif
