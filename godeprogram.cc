# include <godeprogram.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <isinf.h>

typedef double(*DOUBLE_FUNCTION)();
typedef int(*INTEGER_FUNCTION)();
# define REDO_MAX	2
# define GINF		-1e+8
# define GLAMBDA	100.0


GOdeProgram::GOdeProgram(double X0,double X1,int N)
		:GProgram()
{
	/*	The first constructor. It sets the value of
	 *	x0 to X0, the value of x1 to X1 and the value
	 *	of npoints to N. If N is negative, then the
	 *	default value for npoints is 10. All the other
	 *	parameters take zero values.
	 * */
	x0	= X0;
	x1	= X1;
	npoints	= N;
	ptr 	= NULL;
	ode1ff 	= NULL;
	ode2ff 	= NULL;
	fode1ff = NULL;
	fode2ff = NULL;
	if(npoints<=0) npoints=10;
	kind	= 0;
	f0	= 0;
	f1	= 0;
	ff0	= 0;
}

GOdeProgram::GOdeProgram(const char *filename)
	:GProgram()
{
    ptr = new QLibrary(filename);
	/*	If we can not open the dll, then
	 *	we set the values for the parameters to
	 *	default values.
	 * */
    if(ptr==NULL)
	{
		x0 = 0.0;
		x1 = 1.0;
		npoints =10;
		ode1ff=NULL;
		ode2ff=NULL;
		kind=0;
		f0=0;
		f1=0;
		ff0=0;
	}
	else
	{
		/*	We take the parameters from the file.
		 *	If the dll have produced from f77, then
		 *	the functions must have a _ at the end 
		 *	of their names.
		 * */
		DOUBLE_FUNCTION X0,X1,F0,F1,FF0;
		INTEGER_FUNCTION NPOINTS, KIND;

        KIND=(INTEGER_FUNCTION)ptr->resolve("getkind");
        if(KIND==NULL) KIND=(INTEGER_FUNCTION)ptr->resolve("_getkind");
        if(KIND==NULL) KIND=(INTEGER_FUNCTION)ptr->resolve("getkind_");
        if(KIND==NULL) KIND=(INTEGER_FUNCTION)ptr->resolve("_getkind_");
		if(KIND==NULL) kind=ODE1; else kind=KIND();
		
        NPOINTS=(INTEGER_FUNCTION)ptr->resolve("getnpoints");
        if(NPOINTS==NULL) NPOINTS=(INTEGER_FUNCTION)ptr->resolve("_getnpoints");
        if(NPOINTS==NULL) NPOINTS=(INTEGER_FUNCTION)ptr->resolve("getnpoints_");
        if(NPOINTS==NULL) NPOINTS=(INTEGER_FUNCTION)ptr->resolve("_getnpoints_");
		if(NPOINTS==NULL) npoints=10; else npoints=NPOINTS();
		
        X0=(DOUBLE_FUNCTION)ptr->resolve("getx0");
        if(X0==NULL) X0=(DOUBLE_FUNCTION)ptr->resolve("_getx0");
        if(X0==NULL) X0=(DOUBLE_FUNCTION)ptr->resolve("getx0_");
        if(X0==NULL) X0=(DOUBLE_FUNCTION)ptr->resolve("_getx0_");
		if(X0==NULL) x0=0.0; else x0=X0();

        X1=(DOUBLE_FUNCTION)ptr->resolve("getx1");
        if(X1==NULL) X1=(DOUBLE_FUNCTION)ptr->resolve("_getx1");
        if(X1==NULL) X1=(DOUBLE_FUNCTION)ptr->resolve("getx1_");
        if(X1==NULL) X1=(DOUBLE_FUNCTION)ptr->resolve("_getx1_");
		if(X1==NULL) x1=1.0; else x1=X1();
		
        F0=(DOUBLE_FUNCTION)ptr->resolve("getf0");
        if(F0==NULL) F0=(DOUBLE_FUNCTION)ptr->resolve("_getf0");
        if(F0==NULL) F0=(DOUBLE_FUNCTION)ptr->resolve("getf0_");
        if(F0==NULL) F0=(DOUBLE_FUNCTION)ptr->resolve("_getf0_");
		if(F0==NULL) f0=0.0; else f0=F0();

        F1=(DOUBLE_FUNCTION)ptr->resolve("getf1");
        if(F1==NULL) F1=(DOUBLE_FUNCTION)ptr->resolve("_getf1");
        if(F1==NULL) F1=(DOUBLE_FUNCTION)ptr->resolve("getf1_");
        if(F1==NULL) F1=(DOUBLE_FUNCTION)ptr->resolve("_getf1");
		if(F1==NULL) f1=0.0; else f1=F1();

        FF0=(DOUBLE_FUNCTION)ptr->resolve("getff0");
        if(FF0==NULL) FF0=(DOUBLE_FUNCTION)ptr->resolve("_getff0");
        if(FF0==NULL) FF0=(DOUBLE_FUNCTION)ptr->resolve("getff0_");
        if(FF0==NULL) FF0=(DOUBLE_FUNCTION)ptr->resolve("_getff0_");
		if(FF0==NULL) ff0=0.0; else ff0=FF0();

		fode1ff=NULL;
		fode2ff=NULL;

        ode1ff=(GODE1FF)ptr->resolve("ode1ff");
        if(ode1ff==NULL) ode1ff=(GODE1FF)ptr->resolve("_ode1ff");
        if(ode1ff==NULL) fode1ff=(GFODE1FF)ptr->resolve("ode1ff_");
        if(fode1ff==NULL)fode1ff=(GFODE1FF)ptr->resolve("_ode1ff_");

        ode2ff=(GODE2FF)ptr->resolve("ode2ff");
        if(ode2ff==NULL) ode2ff=(GODE2FF)ptr->resolve("_ode2ff");
        if(ode2ff==NULL) fode2ff=(GFODE2FF)ptr->resolve("ode2ff_");
        if(fode2ff==NULL) fode2ff=(GFODE2FF)ptr->resolve("_ode2ff_");
	}
}

void	GOdeProgram::setKind(int k)
{
	/*	If kind is still zero and k is between ODE1 and ODE3, then
	 *	set kind to k.
	 * */
	if(!kind && k>=ODE1 && k<=ODE3) kind=k;
}

void	GOdeProgram::setF0(double f)
{
	/*	Set the value of the left boundary condition to f.
	 * */
	f0 = f;
}

void	GOdeProgram::setF1(double f)
{
	/*	Set the value of the right boundary condition to f.
	 * */
	f1 = f;
}

void	GOdeProgram::setFF0(double f)
{
	/*	Set the value of the derivative of the left boundary to f.
	 * */
	ff0 = f;
}

void	GOdeProgram::setOde1ff(GODE1FF f)
{
	/*	If ode1ff is NULL, then set ode1ff to f.
	 * */
	if(ode1ff==NULL) ode1ff=f;
}

void	GOdeProgram::setOde2ff(GODE2FF f)
{
	/*	If ode2ff is NULL, then set ode2ff to f.
	 * */
	if(ode2ff==NULL) ode2ff=f;
}

int	GOdeProgram::getKind()	const
{
	/*	Return the kind of the equation.
	 * */
	return kind;
}

double	GOdeProgram::getX0()		const
{
	/*	Return the left boundary.
	 * */
	return	x0;
}

double	GOdeProgram::getX1()		const
{
	/*	Return the right boundary.
	 * */
	return x1;
}

double	GOdeProgram::getF0()		const
{
	/*	Return the left boundary condition.
	 * */
	return	f0;
}

double	GOdeProgram::getF1()		const
{
	/*	Return the right boundary condition.
	 * */
	return	f1;
}

double	GOdeProgram::getFF0()	const
{
	/*	Return the derivative of the left
	 *	boundary condition.
	 * */
	return	ff0;
}

double	GOdeProgram::fitness(vector<int> &genome)
{
	int redo=0;
	string str;
	double value=0.0;
        double x[1];
	int code;

	if(kind==ODE1 && ode1ff==NULL && fode1ff==NULL) return GINF;
	if(kind>ODE1 && ode2ff==NULL  && fode2ff==NULL) return GINF;
	if(kind==0) return GINF;

        str=printProgram(genome,redo);
        if(redo>=REDO_MAX)  return GINF;
        code=parser.Parse(str,"x");
	if(code!=-1) return GINF;
        for(int i=0;i<npoints;i++)
        {
        	double X,y,yy,yy2;
                X=x[0]=x0+i*1.0*(x1-x0)/(npoints-1.0);
                if(kind>=ODE2)
                {
 			yy2=parser.EvalDeriv2(x,0);
                        if(parser.EvalError()) return GINF;
                        yy=parser.lastEvalDeriv();
                        y=parser.lastEval();
			if(fode2ff==NULL) value=value+pow(ode2ff(x[0],y,yy,yy2),2.0);
			else              value=value+pow(fode2ff(&X,&y,&yy,&yy2),2.0);
                }
                else
                {
 			yy=parser.EvalDeriv(x,0);
                        if(parser.EvalError()) return GINF;
                        y=parser.lastEval();
			if(fode1ff==NULL) value=value+pow(ode1ff(x[0],y,yy),2.0);
			else		  value=value+pow(fode1ff(&X,&y,&yy),2.0);
                }
                if(std::isnan(value) || std::isinf(value)) return GINF;
        }
        double penalty=0.0;
       	double y,yy,yy2;
        switch(kind)
        {
                case    ODE1:
                        x[0]=x0;
                        y=parser.Eval(x);
                        if(parser.EvalError()) return GINF;
                        penalty=GLAMBDA*pow(y-f0,2.0);
                        break;
                case    ODE2:
                        x[0]=x0;
                        y=parser.Eval(x);
                        if(parser.EvalError()) return GINF;
                        yy=parser.EvalDeriv(x,0);
                        if(parser.EvalError()) return GINF;
                        penalty=GLAMBDA*(pow(y-f0,2.0)+pow(yy-ff0,2.0));
                        break;
                case    ODE3:
                        x[0]=x0;
                        y=parser.Eval(x);
                        if(parser.EvalError()) return GINF;
                        penalty=GLAMBDA*pow(y-f0,2.0);
                        x[0]=x1;
			y=parser.Eval(x);
                        if(parser.EvalError()) return GINF;
                        penalty+=GLAMBDA*pow(y-f1,2.0);
                        break;
        }
        if(std::isnan(penalty) || std::isinf(penalty)) return GINF;
        value=value+penalty;
        if(std::isnan(value) || std::isinf(value)) return GINF;
        return -(value);
}

GOdeProgram::~GOdeProgram()
{
	/*	If we used the second constructor, then we must
	 *	close the dll which opened.
	 * */
    if(ptr!=NULL) delete ptr;
}
