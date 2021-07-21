# ifndef __ODEGRAMMAR_HH
# include <gprogram.h>
class OdeGrammar
{
private:
    GSymbol start,Plus,Minus,mult,xx,expr;
    GSymbol Div,Sin,Cos,Log,Exp;
    GSymbol Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine;
    GSymbol Lpar,Rpar;
    GSymbol digit;
    GSymbol binaryOp;
    GSymbol funcOp;
    GSymbol termOp;
    GSymbol digitList;
    GSymbol dot;

    GRule rule1, rule2, rule3, rule4, rule5, rule6,
                    rule7, rule8,rule9,
                    rule10,rule11,rule12,rule13,
                    rule14, rule15,rule16,
                    rule17, rule18, rule19, rule20,
                    rule21,rule22,rule23,
                    rule24,rule25,rule26;
public:
    void makeTerminals();
    void makeNonTerminals();
    void makeRules();
    GSymbol *getStartSymbol();
};

# define __ODEGRAMMAR__H
# endif
