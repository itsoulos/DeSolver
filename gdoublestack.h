# ifndef __GDOUBLESTACK__H
# include <math.h>
# include <isinf.h>

/**
 * @brief The GDoubleStack class This class implements a stack with double values
 *	on it. It will be used for the differentiation
 *	process in FunctionParser class.
 */
class GDoubleStack
{
	private:
         /**
         * @brief data The table of double values.
         */
		double *data;
        /**
         * @brief counter Counts the amount of elements in data.
         */
		int counter;
	public:
        /**
         * @brief GDoubleStack The default constructor of the class.
         */
		GDoubleStack();
        /**
         * @brief size It returns the amount of elements on the stack.
         * @return
         */
		int  	size() const;
        /**
         * @brief push It adds the x at the end of the stack.
         * @param x
         */
		void 	push(double x);
        /**
         * @brief top It returns the most top element of the stack.
         * @return
         */
		double  top() const;
        /**
         * @brief pop It removes the most top element of the stack.
         * @return
         */
		double 	pop();
        /**
         * @brief clear It clears the stack.
         */
		void	clear();

        /** @brief It deallocates the memory of the stack.
         */
		~GDoubleStack();
};

# define __GDOUBLESTACK__H
# endif
