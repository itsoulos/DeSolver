# include <gpdeprogram.h>
# include <math.h>
# include <isinf.h>

typedef double(*DOUBLE_FUNCTION)();
typedef int(*INTEGER_FUNCTION)();
# define REDO_MAX       2
# define GINF           -1e+8
# define GLAMBDA        100.0

GPdeProgram::GPdeProgram(double X0,double X1,double Y0,double Y1,int n,int b)
{
	/*	The first constructor of the class.
	 *	It sets the value for the boundaries, the
	 *	training points and the boundary points. The
	 *	other parameters must set with other methods.
	 * */
	x0 = X0;
	x1 = X1;
	y0 = Y0;
	y1 = Y1;
	npoints = n;
	if(npoints<0) npoints=25;
	bpoints = b;
	if(bpoints<0) bpoints=50;
	f0=NULL;
	f1=NULL;
	g0=NULL;
	g1=NULL;
	ff0=NULL;
	ff1=NULL;
	fg0=NULL;
	fg1=NULL;
	pde=NULL;
	fpde=NULL;
	ptr=NULL;
}

GPdeProgram::GPdeProgram(const char *filename)
{
	/*	The second constructor. It tries to load the 
	 *	parameters from the dll filename. If the dll
	 *	can not be opened, the it uses default values
	 *	for the parameters.
	 * */
    ptr=new QLibrary(filename);
    if(ptr==NULL)
	{
	x0 = 0.0;
	x1 = 1.0;
	y0 = 0.0;
	y1 = 1.0;
	npoints = 25;
	bpoints = 50;
	f0=NULL;
	f1=NULL;
	g0=NULL;
	g1=NULL;
	ff0=NULL;
	ff1=NULL;
	fg0=NULL;
	fg1=NULL;
	pde=NULL;
	fpde=NULL;
	ptr=NULL;
	}
	else
	{
		INTEGER_FUNCTION NPOINTS, BPOINTS;
		DOUBLE_FUNCTION X0, X1, Y0, Y1;

        NPOINTS=(INTEGER_FUNCTION)ptr->resolve("getnpoints");
		if(NPOINTS==NULL) 
            NPOINTS=(INTEGER_FUNCTION)ptr->resolve("_getnpoints");
		if(NPOINTS==NULL) 
            NPOINTS=(INTEGER_FUNCTION)ptr->resolve("getnpoints_");
		if(NPOINTS==NULL) 
            NPOINTS=(INTEGER_FUNCTION)ptr->resolve("_getnpoints_");
		if(NPOINTS==NULL) npoints=25; else npoints=NPOINTS();

        BPOINTS=(INTEGER_FUNCTION)ptr->resolve("getbpoints");
		if(BPOINTS==NULL) 
            BPOINTS=(INTEGER_FUNCTION)ptr->resolve("_getbpoints");
		if(BPOINTS==NULL) 
            BPOINTS=(INTEGER_FUNCTION)ptr->resolve("getbpoints_");
		if(BPOINTS==NULL) 
            BPOINTS=(INTEGER_FUNCTION)ptr->resolve("_getbpoints_");
		if(BPOINTS==NULL) bpoints=50; else bpoints=BPOINTS();

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

		ff0=NULL;
		ff1=NULL;
		fg0=NULL;
		fg1=NULL;
		fpde=NULL;

        Y0=(DOUBLE_FUNCTION)ptr->resolve("gety0");
        if(Y0==NULL) Y0=(DOUBLE_FUNCTION)ptr->resolve("_gety0");
        if(Y0==NULL) Y0=(DOUBLE_FUNCTION)ptr->resolve("gety0_");
        if(Y0==NULL) Y0=(DOUBLE_FUNCTION)ptr->resolve("_gety0_");
		if(Y0==NULL) y0=0.0; else y0=Y0();

        Y1=(DOUBLE_FUNCTION)ptr->resolve("gety1");
        if(Y1==NULL) Y1=(DOUBLE_FUNCTION)ptr->resolve("_gety1");
        if(Y1==NULL) Y1=(DOUBLE_FUNCTION)ptr->resolve("gety1_");
        if(Y1==NULL) Y1=(DOUBLE_FUNCTION)ptr->resolve("_gety1_");
		if(Y1==NULL) y1=0.0; else y1=Y1();

        f0=(GBOUNDF)ptr->resolve("f0");
        if(f0==NULL) ff0=(GFBOUNDF)ptr->resolve("_f0");
        if(f0==NULL) ff0=(GFBOUNDF)ptr->resolve("f0_");
        if(ff0==NULL) ff0=(GFBOUNDF)ptr->resolve("_f0_");

        f1=(GBOUNDF)ptr->resolve("f1");
        if(f1==NULL) f1=(GBOUNDF)ptr->resolve("_f1");
        if(f1==NULL) ff1=(GFBOUNDF)ptr->resolve("f1_");
        if(ff1==NULL) ff1=(GFBOUNDF)ptr->resolve("_f1_");

        g0=(GBOUNDF)ptr->resolve("g0");
        if(g0==NULL) g0=(GBOUNDF)ptr->resolve("_g0");
        if(g0==NULL) fg0=(GFBOUNDF)ptr->resolve("g0_");
        if(fg0==NULL) fg0=(GFBOUNDF)ptr->resolve("_g0_");

        g1=(GBOUNDF)ptr->resolve("g1");
        if(g1==NULL) g1=(GBOUNDF)ptr->resolve("_g1");
        if(g1==NULL) fg1=(GFBOUNDF)ptr->resolve("g1_");
        if(fg1==NULL) fg1=(GFBOUNDF)ptr->resolve("_g1_");

        pde=(GPDE)ptr->resolve("pde");
        if(pde==NULL) pde=(GPDE)ptr->resolve("_pde");
        if(pde==NULL) fpde=(GFPDE)ptr->resolve("pde_");
        if(fpde==NULL) fpde=(GFPDE)ptr->resolve("_pde_");
	}
}

double	GPdeProgram::getX0() const
{
	/*	Return the left boundary at xx'.
	 * */
	return x0;
}

double  GPdeProgram::getX1() const
{
	/*	Return the right boundary at xx'.
	 * */
	return x1;
}

double  GPdeProgram::getY0() const
{
	/*	Return the left boundary at yy'.
	 * */
	return y0;
}

double	GPdeProgram::getY1() const
{
	/*	Return the right boundary at yy'.
	 * */
	return y1;
}

double  GPdeProgram::getNpoints() const
{
	/*	Return the amount of training points.
	 * */
	return npoints;
}

double  GPdeProgram::getBoundaryPoints() const
{
	/*	Return the amount of boundary points.
	 * */
	return bpoints;
}

void	GPdeProgram::setBoundaries(GBOUNDF F0,GBOUNDF F1,GBOUNDF G0,GBOUNDF G1)
{
	/*	Set the boundary conditions.
	 * */
	if(f0==NULL)
	{
		f0=F0;
		f1=F1;
		g0=G0;
		g1=G1;
	}
}

void	GPdeProgram::setPde(GPDE p)
{
	/*	Set the pde to be solved.
	 * */
	if(pde==NULL) pde=p;
}

double GPdeProgram::fitness(vector<int> &genome)
{
	/*	Estimate the fitness for the integer variable genome.
	 * */
	if(pde==NULL && fpde==NULL) return GINF;
	int redo=0;
        string str=printProgram(genome,redo);

        if(redo>=REDO_MAX) return GINF;
        double value=0.0;

        double x[2];
        double X,y,Y;
        int code=parser.Parse(str,"x,y");
	if(code!=-1) return GINF;
        double penalty1=0.0,penalty2=0.0,penalty3=0.0,penalty4=0.0;

        double val1,val2,val3,val4;
        double stepx=(x1-x0)/bpoints;
        double stepy=(y1-y0)/bpoints;

	/*	Calculation of the penalties.
	 * */
        for(X=x0;X<=x1;X+=stepx)
        {
                x[0]=X;
                x[1]=y0;
		if(fg0==NULL) val1=g0(X); else val1=fg0(&X);
                penalty3+=pow(parser.Eval(x)-val1,2.0);
                if(parser.EvalError()) return GINF;
                x[1]=y1;
		if(fg1==NULL) val2=g1(X); else val2=fg1(&X);
                penalty4+=pow(parser.Eval(x)-val2,2.0);
                if(parser.EvalError()) return GINF;
        }
 	for(y=y0;y<=y1;y+=stepy)
        {
                x[0]=x0;
                x[1]=y;
		if(ff0==NULL) val3=f0(y); else val3=ff0(&y);
                penalty1+=pow(parser.Eval(x)-val3,2.0);
                if(parser.EvalError()) return GINF;
                x[0]=x1;
		if(ff1==NULL) val4=f1(y); else val4=ff1(&y);
                penalty2+=pow(parser.Eval(x)-val4,2.0);
                if(parser.EvalError()) return GINF;
        }
        if(std::isnan(penalty1) || std::isinf(penalty1)) return GINF;
        if(std::isnan(penalty2) || std::isinf(penalty2)) return GINF;
        if(std::isnan(penalty3) || std::isinf(penalty3)) return GINF;
        if(std::isnan(penalty4) || std::isinf(penalty4)) return GINF;


	/*	Calculation of the fitness.
	 * */
        stepx=(x1-x0)/(int)(sqrt(1.0*npoints));
        stepy=(y1-y0)/(int)(sqrt(1.0*npoints));
        for(Y=y0;Y<y1+0.01;Y+=stepy)
        {
                for(X=x0;X<x1+0.01;X+=stepx)
                {
                        x[0]=X;
                        x[1]=Y;
                        double valx2=parser.EvalDeriv2(x,0);
                        if(parser.EvalError()) return GINF;
                        double valy2=parser.EvalDeriv2(x,1);
                        if(parser.EvalError()) return GINF;
                        double valx1=parser.EvalDeriv(x,0);
                        double valy1=parser.EvalDeriv(x,1);
                        double val=parser.Eval(x);
			if(fpde==NULL)
                        value = value +pow(pde(X,Y,val,valx1,valy1,valx2,valy2),2.0);
			else    
                        value = value +pow(fpde(&X,&Y,&val,&valx1,&valy1,&valx2,&valy2),2.0);
                        if(std::isnan(value) || std::isinf(value))  return GINF;
                }
        }
        double p=penalty1+penalty2+penalty3+penalty4;
        value+=p/4.0;
        if(std::isnan(value) || std::isinf(value)) return GINF;
	return -value;
}

GPdeProgram::~GPdeProgram()
{
	/*	The destructor of the class. It closes the dll pointed
	 *	by ptr, if it has opened.
	 * */
    if(ptr!=NULL) delete ptr;
}
