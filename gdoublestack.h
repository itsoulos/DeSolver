# ifndef __GDOUBLESTACK__H
# include <math.h>
# include <isinf.h>

/*	CLASS DESCRIPTION
 *	=================
 *	This class implements a stack with double values
 *	on it. It will be used for the differentiation 
 *	process in FunctionParser class.
 * */

class GDoubleStack
{
	private:
		/*	PRIVATE FIELDS
		 *	==============
		 *	data:	The table of double values.
		 *	counter: Counts the amount of elements in data.
		 * */
		double *data;
		int counter;
	public:
		/*	PUBLIC FIELDS
		 *	=============
		 *	GDoubleStack():		The default constructor of the class.
		 *	size():			It returns the amount of elements on the stack.
		 *	push(x):		It adds the x at the end of the stack.
		 *	top():			It returns the most top element of the stack.
		 *	pop():			It removes the most top element of the stack.
		 *	clear():		It clears the stack.
		 *	~GDoubleStack():	It deallocates the memory of the stack.
		 * */
		GDoubleStack();
		int  	size() const;
		void 	push(double x);
		double  top() const;
		double 	pop();
		void	clear();
		~GDoubleStack();
};

# define __GDOUBLESTACK__H
# endif
