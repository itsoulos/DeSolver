# ifndef __GPROGRAM__H
# include <gsymbol.h>
# include <grule.h>
# include <QLibrary>
# include <QString>
# include <vector>
using namespace std;

/*	CLASS DESCRIPTION
 *	=================
 *	This class represents an entire program in
 *	the grammatical evolution. 
 * */
class GProgram
{
	private:
		/*	PRIVATE FIELDS
		 *	==============
		 *	start_symbol:	The starting symbol of the grammar. The memory for
		 *			that symbol must has been previously allocated.
		 * */
		GSymbol *start_symbol;
	public:
		/*	PUBLIC FIELDS
		 *	=============
		 *	GProgram():			The default constructor of the class.
		 *	GProgram(s):			The second constructor of the class. It sets
		 *					the start_symbol to s.
		 *	setStartSymbol(s):		It sets the start_symbol to s.
		 *	getStartSymbol():		It returns the starting symbol of the grammar.
		 *	printProgram(genome,redo):	It returns a string, which represents the program
		 *					induced by the grammar and the integer array genome. 
		 *					The value of redo initially must be set to zero. At the
		 *					end it holds the number of wrapping events occured. If the
		 *					value of redo is greater than or equal to a predefined value,
		 *					then the user must declare the program as invalid.
		 *	fitness(genome):		It is a virtual method, that maps a double value to a program,
		 *					which is represented by the grammar and the integer array
		 *					genome. The user must redefine the method in order to 
		 *					adapt the grammar to his problem. For the base class 
		 *					this method always returns zero.
		 * */
		GProgram();
		GProgram(GSymbol *s);
		void		setStartSymbol(GSymbol *s);
		GSymbol		*getStartSymbol() const;
		string		printProgram(vector<int> &genome,int &redo);
		virtual double	fitness(vector<int> &genome);
};

# define __GPROGRAM__H
# endif
