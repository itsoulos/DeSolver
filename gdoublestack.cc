# include <gdoublestack.h>
# include <stdlib.h>
# include <math.h>
# include <isinf.h>

GDoubleStack::GDoubleStack()
{
	/*	The default constructor of the class.
	 *	It allocates 512 doubles to the stack,
	 *	in order to accelarate the processes 
	 * 	of push and pop.
	 * */
	data = (double*)malloc(512*sizeof(double));
	counter =0;
}

void	GDoubleStack::clear()
{
	/*	Set the counter of elements to zero.
	 *	The stack may be considered as empty.
	 * */
	counter = 0;
}

int	GDoubleStack::size() const
{
	/*	Return the amount of elements on
	 *	the stack.
	 * */
	return counter;
}

void GDoubleStack::push(double x)
{
	/*	Add the element x at the end of
	 *	the stack. If we need more space 
	 *	from the stack, we allocate it.
	 * */
	if(isnan(x) || isinf(x)) {x=1e+8;}
	if(counter>=512) 
	{
		data=(double*)realloc(data,(counter+1)*sizeof(double));
	}
	data[counter]=x;
	counter++;
}

double  GDoubleStack::top() const
{
	/*	Return the top most element of the stack. 
	 *	If the stack is empty return -1.
	 * */
	return (counter!=0)?data[counter-1]:-1;
}

double  GDoubleStack::pop()
{
	/*	Remove and return the top most element of
	 *	the stack. If the stack is empty return -1.
	 * */
	if(!counter) return -1;
	double t=data[counter-1];
	counter--;
	return t;
}

GDoubleStack::~GDoubleStack()
{
	/*	Deallocate the memory of the stack.
	 * */
	free(data);
}
