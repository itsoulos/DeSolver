# include <gprogram.h>
class PdeGrammar
{
private:
    GSymbol start,Plus,Minus,mult,xx, yy, expr;
    GSymbol Div,Sin,Cos,Log,Exp;
    GSymbol Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine;
    GSymbol Lpar,Rpar;
    GSymbol digit;
    GSymbol binaryOp;
    GSymbol funcOp;
    GSymbol termOp;


    GRule rule1, rule2, rule3, rule4, rule5, rule6,
                    rule7, rule8,rule9,
                    rule10,rule11,rule12,rule13,
                    rule14, rule15,rule16,
                    rule17, rule18, rule19, rule20,
                    rule21,rule22,rule23,
                    rule24,rule25,rule26, rule27, rule28;
public:
    void makeTerminals();
    void makeNonTerminals();
    void makeRules();
    GSymbol *getStartSymbol();
};


