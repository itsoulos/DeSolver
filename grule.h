# ifndef __GRULE__H
# include <gsymbol.h>
# include <vector>
using namespace std;

/*	CLASS DESCRIPTION
 *	=================
 *	This class represents the rules in the BNF grammar. It relies heavily 
 *	on the class GSymbol.
 * */

class GRule
{
	private:
		/*	PRIVATE FIELDS
		 *	===============
		 *	redo_max:	This is the maximum number of wrapping events allowed, 
		 *			before we stop the processing of the rule.
		 *	data:		This is the list of the symbols, that comprise this rule.
		 *			The memory for every symbol in the list, must be allocated
		 *			before in the program.
		 * */
		int    		redo_max;
		vector<GSymbol*> data;	
	public:
		/*	PUBLIC FIELDS
		 *	===============
		 *	GRule():			The default constructor of the class.
		 *	GRule(Wrapping):		The second constructor of the class. It sets
		 *					the maximum number of allowed wrapping events
		 *					to the parameter Wrapping.
		 *	addSymbol(s):			It adds the symbol pointed by s to the end of 
		 *					the symbol list.
		 *	getSymbol(pos):			It returns the pointer of the symbol in position 
		 *					pos in the symbol list. In case that pos is negative
		 *					or greater than the size of symbol list, it returns NULL.
		 *	setSymbol(pos,s):		It sets the symbol at position pos of the symbol list to 
		 *					s. If the pos is negative of greater than the size of the
		 *					list it does nothing.
		 *	getLength():			It returns the size of the symbol list.
		 *	getWrappingNumber():		It returns the maximum number of the allowed 
		 *					wrapping events.
		 *	printRule(genome,pos,redo):	It returns the string represent by the integer value genome and
		 *					which is associated with the current rule.Every value in the 
		 *					table genome is a rule that we must follow, if we reach a non
		 *					terminal symbol in the rule list. Initially the user must set
		 *					the values of pos and redo to zero. At the end, the value of
		 *					redo indicates the number of wrapping events occured. If the
		 *					value of redo is greater than or equal to the maximum number
		 *					of the wrapping events, then the method printRule() has failed.
		 * */
		GRule();
		GRule(int Wrapping);
		void	addSymbol(GSymbol *s);
		int	getSymbolPos(string s);
		GSymbol	*getSymbol(int pos) 	const;
		void	setSymbol(int pos,GSymbol *s);
		int	getLength() 		const;
		int	getWrappingNumber()	const;
		string	printRule(vector<int> genome,int &pos,int &redo);
};


# define __GRULE__H
# endif
