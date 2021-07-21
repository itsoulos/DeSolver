# include <gprogram.h>		

/*	The implementation of the class gprogram.
 * */


GProgram::GProgram()
{
	/*	The default constructor. 
	 *	The default value for start_symbol is NULL.
	 * */
	start_symbol = NULL;
}

GProgram::GProgram(GSymbol *s)
{
	/*	Set the value of start_symbol to s.
	 * */
	start_symbol = s;
}

void	GProgram::setStartSymbol(GSymbol *s)
{
	/*	Set the value of start_symbol to s.
	 * */
	start_symbol = s;
}

GSymbol	*GProgram::getStartSymbol() const
{
	/*	Return the value of the starting symbol.
	 * */
	return start_symbol;
}


string	GProgram::printProgram(vector<int> &genome,int &redo)
{
	/*	Return the program represented by the rules in genome.
	 *	Initially the value of redo must be set to zero. After 
	 *	the method has done, the user must check the value of
	 *	redo, in order to understand if the maximum number of
	 *	wrapping events has been reached.
	 * */
	/*	str:	The returning program.
	 *	count:	Initially is zero. 
	 *	r,pos:  Auxiliary variables.
	 * */
	string str="";
	int count=0;
	GRule *r;
	int pos;
	if(start_symbol == NULL) return "";

	/*	Take the first rule from the starting symbol and proceed.
	 * */
	r=start_symbol->getRule(0);
	redo = 0;
	str=r->printRule(genome,count,redo);
	return str;
}

double	GProgram::fitness(vector<int> &genome)
{
	/*	This method must be redefined by the derived classes, in 
	 *	order to assign values to programs.
	 * */
	return 0.0;
}

