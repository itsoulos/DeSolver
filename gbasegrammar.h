#ifndef GBASEGRAMMAR_H
#define GBASEGRAMMAR_H
# include <gprogram.h>


class GBaseGrammar
{
protected:
    GSymbol start,Plus,Minus,mult, expr;
    GSymbol Div,Sin,Cos,Log,Exp,Dot;
    GSymbol Lpar,Rpar,Xsymbol,Ysymbol;
    GSymbol binaryOp,funcOp,termOp,Pow,Digit0,Digit1,DigitList,Terminal;
    vector<GRule*> rule;
    int newRule();
    vector<GSymbol> Digit;
public:
    GBaseGrammar();
    void makeTerminals();
    void makeNonTerminals();
    void makeRules();
    GSymbol *getStartSymbol();
};

#endif // GBASEGRAMMAR_H
