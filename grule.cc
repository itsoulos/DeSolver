# include <grule.h>
# include <iostream>

/*	The implementation of the class GRule
 * */



GRule::GRule()
{
	/*	The default constructor.
	 *	The default value of the maximum allowed wrapping events is 2.
	 * */
	redo_max = 2;
}

GRule::GRule(int Wrapping)
{
	/*	Set the value of maximum allowed wrapping events to Wrapping. 
	 * */
	redo_max = Wrapping;	
}

void	GRule::addSymbol(GSymbol *s)
{
	/*	Add the symbol s to the end of the symbol list. 
	 * */
	data.push_back(s);
}

int	GRule::getSymbolPos(string s)
{
	/*	Return the position in the symbol list of the symbol with name s.
	 * */
	int length = data.size();
	for(int i=0;i<length;i++)
		if(data[i]->getName()==s) return i;
	return -1;
}

GSymbol	*GRule::getSymbol(int pos) const
{
	/*	If pos is between 0 and data.size()-1 return the pointer in that position,
	 *	otherwise return NULL.
	 * */
	if(pos<0 || pos>=data.size()) return NULL;
	return data[pos];
}

void	GRule::setSymbol(int pos,GSymbol *s)
{
	/*	Set the symbol at the position pos to s, if the pos is between 
	 *	zero and data.size()-1
	 * */
	if(pos<0 || pos>=data.size()) return; 
	data[pos]=s;
}

int	GRule::getLength() const
{
	/*	Return the size of the symbol list.
	 * */
	return data.size();
}

string	GRule::printRule(vector<int> genome,int &pos,int &redo)
{
	/*	This is the major method of the class.
	 * */
	/*	str:	The returning value of the method.
	 *	r,str2:	Auxiliary variables.
	 * */
	string str="";
	string str2="";
	GRule *r;
	int length=data.size();
	for(int i=0;i<length;i++)
	{
		/*	If the symbol is a terminal one, then we concat its name
		 *	to the end of the returning variable, otherwise recursivly
		 *	we call the printRule() for that symbol and we append 
		 *	the resulting string to the end of the returning variable.
		 * */
		GSymbol *s=data[i];
		if(s->getTerminalStatus())
			str=str+s->getName();	
		else
		{
			/*	If we pass the end of the genome, then we start over from
			 *	the first position of the genome. For that reason we increase
			 *	the value of redo (wrapping events) and we set to zero the 
			 *	value of pos.
			 * */
			if(pos>=genome.size()) {redo++;pos=0;}
			/*	We use the mod rule in order to select the rule that we must follow.
			 * */
			r=s->getRule((genome[pos]%s->getCountRules()));
			pos++;
			if(pos>=genome.size()) {redo++;pos=0;}
			/*	If we reach the maximum number of wrapping events allowed, we
			 *	return the string that we make so far.  Ïbviously the user must
			 *	check the value of reference redo.
			 * */
			if(redo>=redo_max) return str;
			str2=r->printRule(genome,pos,redo);
			str=str+str2;
		}
	}
	/*	Finally, we return the string obtained from the method.
	 * */
	return str;
}
