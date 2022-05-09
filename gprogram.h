# ifndef __GPROGRAM__H
# include <gsymbol.h>
# include <grule.h>
# include <QLibrary>
# include <QString>
# include <vector>
using namespace std;

/**
 * @brief The GProgram class represents an entire program in
 *	the grammatical evolution.
 */
class GProgram
{
	private:
        /**
         * @brief start_symbol The starting symbol of the grammar. The memory for
         *			that symbol must has been previously allocated.
         */
		GSymbol *start_symbol;
	public:
        /**
         * @brief GProgram The default constructor of the class.
         */
		GProgram();
        /**
         * @brief GProgram The second constructor of the class. It sets
         *					the start_symbol to s.
         * @param s
         */
		GProgram(GSymbol *s);
        /**
         * @brief setStartSymbol It sets the start_symbol to s.
         * @param s
         */
		void		setStartSymbol(GSymbol *s);
        /**
         * @brief getStartSymbol It returns the starting symbol of the grammar.
         * @return
         */
		GSymbol		*getStartSymbol() const;
        /**
         * @brief printProgram It returns a string, which represents the program
         *					induced by the grammar and the integer array genome.
         *					The value of redo initially must be set to zero. At the
         *					end it holds the number of wrapping events occured. If the
         *					value of redo is greater than or equal to a predefined value,
         *					then the user must declare the program as invalid.
         * @param genome
         * @param redo
         * @return
         */
		string		printProgram(vector<int> &genome,int &redo);
        /**
         * @brief fitness It is a virtual method, that maps a double value to a program,
         *					which is represented by the grammar and the integer array
         *					genome. The user must redefine the method in order to
         *					adapt the grammar to his problem. For the base class
         *					this method always returns zero.
         * @param genome
         * @return
         */
		virtual double	fitness(vector<int> &genome);
};

# define __GPROGRAM__H
# endif
