# ifndef __GRULE__H
# include <gsymbol.h>
# include <vector>
using namespace std;
/**
 * @brief The GRule class  represents the rules in the BNF grammar. It relies heavily
 *	on the class GSymbol.
 */
class GRule
{
	private:
        /**
         * @brief redo_max This is the maximum number of wrapping events allowed,
         *			before we stop the processing of the rule.
         */
        int    		redo_max;
        /**
         * @brief data This is the list of the symbols, that comprise this rule.
         *			The memory for every symbol in the list, must be allocated
         *			before in the program.
         */
		vector<GSymbol*> data;	
	public:
        /**
         * @brief GRule The default constructor of the class.
         */
		GRule();
        /**
         * @brief GRule The second constructor of the class. It sets
         *					the maximum number of allowed wrapping events
         *					to the parameter Wrapping.
         * @param Wrapping
         */
		GRule(int Wrapping);
        /**
         * @brief addSymbol It adds the symbol pointed by s to the end of
         *					the symbol list.
         * @param s
         */
		void	addSymbol(GSymbol *s);
        /**
         * @brief getSymbolPos It returns the position of a symbol in the list
         * @param s
         * @return
         */
		int	getSymbolPos(string s);
        /**
         * @brief getSymbol It returns the pointer of the symbol in position
         *					pos in the symbol list. In case that pos is negative
         *					or greater than the size of symbol list, it returns NULL.
         * @param pos
         * @return
         */
		GSymbol	*getSymbol(int pos) 	const;
        /**
         * @brief setSymbol It sets the symbol at position pos of the symbol list to
         *					s. If the pos is negative of greater than the size of the
         *					list it does nothing.
         * @param pos
         * @param s
         */
		void	setSymbol(int pos,GSymbol *s);
        /**
         * @brief getLength 	It returns the size of the symbol list.
         * @return
         */
		int	getLength() 		const;
        /**
         * @brief getWrappingNumber It returns the maximum number of the allowed
         *					wrapping events.
         * @return
         */
		int	getWrappingNumber()	const;
        /**
         * @brief printRule It returns the string represent by the integer value genome and
         *					which is associated with the current rule.Every value in the
         *					table genome is a rule that we must follow, if we reach a non
         *					terminal symbol in the rule list. Initially the user must set
         *					the values of pos and redo to zero. At the end, the value of
         *					redo indicates the number of wrapping events occured. If the
         *					value of redo is greater than or equal to the maximum number
         *					of the wrapping events, then the method printRule() has failed.
         * @param genome
         * @param pos
         * @param redo
         * @return
         */
		string	printRule(vector<int> genome,int &pos,int &redo);
};


# define __GRULE__H
# endif
