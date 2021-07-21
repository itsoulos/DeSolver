# include <gsymbol.h>

/*	The implementation of the class GSymbol.
 * */



GSymbol::GSymbol()
{
	/*	DEFAULT VALUES
	 *	==============
	 *	Set the name to null, and the status to 1. This mean 
	 *	that the symbol is terminal with name " "
	 * */
	name = "";
	is_terminal = 1;
}


GSymbol::GSymbol(string s,int status)
{
	/*	Set the name to s and is_terminal to status.
	 * */
	name = s;
	is_terminal = status;
}

void	GSymbol::setName(string s)
{
	/*	Set the name to the first parameter.
	 * */
	name = s;
}

string	GSymbol::getName() const
{
	/*	Return the name of the symbol.
	 * */
	return name;
}

void	GSymbol::setTerminalStatus(int status)
{
	/*	Set the terminal status flag.
	 * */
	is_terminal=status;
}

int	GSymbol::getTerminalStatus() const
{
	/*	Return the terminal status.	
	 * */
	return is_terminal;
}

void	GSymbol::addRule(GRule *r)
{
	/*	If the value of r is not NULL, add it to the list of rules.
	 *	For security reasons, we do not allow null rules.
	 * */
	if(r!=NULL) rule.push_back(r);
}

GRule	*GSymbol::getRule(int pos) const
{
	/*	Return the rule at position pos. If pos is negative or greater
	 *	of the amount of rules, we return NULL. We choose to return NULL
	 *	for security reasons. The program of the user is responsible 
	 *	to check the  return status of this method.
	 * */
	int count_rules=rule.size();
	if(pos<0 || pos>=count_rules) return NULL;
	return rule[pos];
}

int	GSymbol::getCountRules() const
{
	/*	Return the amount of rules in the rule list.
	 * */
	return rule.size();
}

void	GSymbol::cut(int N)
{
	/*	Reduce the amount of rules to N. The last rule.size()-N will be cut off. 
	 *	This method can not increase the amount of rules, for security reasons.
	 * */
	if(N<0 || N>=rule.size()) return;
	rule.resize(N);
}
