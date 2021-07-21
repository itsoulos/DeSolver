# ifndef __GSYMBOL__H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <vector>
using namespace std;

/*	CLASS DESCRIPTION
 *	=================
 *	This class represents the symbols of the grammar. 
 *	The class is general enough to describe terminal
 *	and non - terminal symbols.
 * */


/*
 *	Forward declaration of the class GRule
 * */
class GRule;

class GSymbol
{
	private:
		/*	PRIVATE FIELDS
		 *	===============
		 *	name: 		The name of the symbol
		 *	rule:		The table of rule pointers of the symbol. 
		 *	      		If the symbol is a terminal one, this table is empty.
		 *	is_terminal: 	If the symbol is terminal, this flag has value 1, 
		 *		        otherwise it set to 0.
		 * */
		string 		name;
		vector<GRule*> 	rule;
		int		is_terminal;
	public:
		/*	PUBLIC FIELDS
		 *	=============
		 *	GSymbol():			The constructor default of the class.
		 *	GSymbol(s,status):		The second constructor of the class. It
		 *				        set the name of the symbol to s and the 
		 *				        status of the symbol to status.
		 *	setName(s):			It sets the name of the symbol to s.
		 *	setTerminalStatus(status):	It sets the status of the class. If the value 
		 *	                                of status is 0, then the symbol is non - terminal, 
		 *	                                otherwise it is considered as terminal.
		 *	getTerminalStatus():		It returns the kind of the symbol.
		 *	addRule(r):			It adds the GRule pointed by r to the rule list. 
		 *					The value  of r must not be NULL.
		 *	cut(N):		        	It reduces the amount of rules of the symbol to N. 
		 *					If N is  greater than the current amount of rules, 
		 *					it does nothing.	
		 *	getRule(pos):			It returns the rule at position pos. If pos is 
		 *	                                less than zero or greater than the amount of rules, 
		 *	                                it returns NULL.
		 *	getCountRules():	 	It returns the amount of rules of the symbol.
		 * */
		GSymbol();
		GSymbol(string s,int status);
		void	setName(string s);
		string	getName() const;
		void	setTerminalStatus(int status);
		int	getTerminalStatus() const;
		void	addRule(GRule *r);
		void	cut(int N);
		GRule	*getRule(int pos) const;
		int	getCountRules() const;
		
};

# define __GSYMBOL__H
# endif
