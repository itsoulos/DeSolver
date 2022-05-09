# ifndef __GSYMBOL__H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <vector>
using namespace std;


class GRule;

/**
 * @brief The GSymbol class. This class represents the symbols of the grammar.
 *	The class is general enough to describe terminal
 *	and non - terminal symbols.
 */
class GSymbol
{
	private:
        /**
         * @brief name The name of the symbol
         */
		string 		name;
        /**
         * @brief rule The table of rule pointers of the symbol.
         *	      		If the symbol is a terminal one, this table is empty.
         */
		vector<GRule*> 	rule;
        /**
         * @brief is_terminal If the symbol is terminal, this flag has value 1,
         *		        otherwise it set to 0.
         */
		int		is_terminal;
	public:
        /**
         * @brief GSymbol The default constructor of the class.
         */
        GSymbol();
        /**
         * @brief GSymbol The second constructor of the class. It
         *				        set the name of the symbol to s and the
         *				        status of the symbol to status.
         * @param s The desired name.
         * @param status the desired status.
         */
		GSymbol(string s,int status);
        /**
         * @brief set the name to s and status to status.
         * @param s
         * @param status
         */
        void    set(string s,int status);
        /**
         * @brief setName It sets the name of the symbol to s.
         * @param s
         */
		void	setName(string s);
        /**
         * @brief getName
         * @return  the name of the symbol.
         */
		string	getName() const;
        /**
         * @brief setTerminalStatus It sets the status of the class. If the value
         *	                                of status is 0, then the symbol is non - terminal,
         *	                                otherwise it is considered as terminal.
         * @param status
         */
		void	setTerminalStatus(int status);
        /**
         * @brief getTerminalStatus
         * @return  It returns the kind of the symbol.
         */
		int	getTerminalStatus() const;
        /**
         * @brief addRule It adds the GRule pointed by r to the rule list.
         *					The value  of r must not be NULL.
         * @param r
         */
		void	addRule(GRule *r);
        /**
         * @brief cut It reduces the amount of rules of the symbol to N.
         *					If N is  greater than the current amount of rules,
         *					it does nothing.
         * @param N
         */
		void	cut(int N);
        /**
         * @brief getRule It returns the rule at position pos. If pos is
         *	                                less than zero or greater than the amount of rules,
         *	                                it returns NULL.
         * @param pos
         * @return
         */
		GRule	*getRule(int pos) const;
        /**
         * @brief getCountRules It returns the amount of rules of the symbol.
         * @return
         */
		int	getCountRules() const;
		
};

# define __GSYMBOL__H
# endif
