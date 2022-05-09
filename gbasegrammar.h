#ifndef GBASEGRAMMAR_H
#define GBASEGRAMMAR_H
# include <gprogram.h>

/**
 * @brief The GBaseGrammar class provides the description of
 * the base grammar used in de solving.
 */
class GBaseGrammar
{
protected:
    /**
     * @brief start The start symbol of the grammar.
     */
    GSymbol start;
    /**
     * @brief Plus The + symbol
     */
    GSymbol Plus;
    /**
     * @brief Minus The - symbol
     */
    GSymbol Minus;
    /**
     * @brief mult The * symbol
     */
    GSymbol mult;
    /**
     * @brief expr The non terminal symbol expr
     */
    GSymbol expr;

    /**
     * @brief Div The / symbol
     */
    GSymbol Div;
    /**
     * @brief Sin the sin(x) function
     */
    GSymbol Sin;
    /**
     * @brief Cos the cos(x) function
     */
    GSymbol Cos;
    /**
     * @brief Log the log(x) function
     */
    GSymbol Log;
    /**
     * @brief Exp the exp(x) function
     */
    GSymbol Exp;
    /**
     * @brief Dot the . symbol for double numbers.
     */
    GSymbol Dot;

    /**
     * @brief Lpar the ( symbol
     */
    GSymbol Lpar;
    /**
     * @brief Rpar The ) symbol
     */
    GSymbol Rpar;
    /**
     * @brief Xsymbol the x terminal symbol
     */
    GSymbol Xsymbol;
    /**
     * @brief Ysymbol the y terminal symbol
     */
    GSymbol Ysymbol;

    /**
     * @brief binaryOp the binaryop non terminal symbol
     */
    GSymbol binaryOp;
    /**
     * @brief funcOp the funcop non terminal symbol
     */
    GSymbol funcOp;
    /**
     * @brief termOp The termop non terminal symbol
     */
    GSymbol termOp;
    /**
     * @brief Pow the operator of power.
     */
    GSymbol Pow;
    /**
     * @brief Digit0 digits with the zero symbol
     */
    GSymbol Digit0;
    /**
     * @brief Digit1 digits without the zero symbol
     */
    GSymbol Digit1;
    /**
     * @brief DigitList the non terminal symbol digitlist
     */
    GSymbol DigitList;
    /**
     * @brief Terminal the non terminal symbol terminal
     */
    GSymbol Terminal;
    /**
     * @brief rule the list with the rules
     */
    vector<GRule*> rule;
    /**
     * @brief newRule
     * @return  a new rule
     */
    int newRule();
    /**
     * @brief Digit the terminal symbols for the digits [0..9]
     */
    vector<GSymbol> Digit;
public:
    /**
     * @brief GBaseGrammar the default constructor
     */
    GBaseGrammar();
    /**
     * @brief makeTerminals method to create terminal symbols
     */
    void makeTerminals();
    /**
     * @brief makeNonTerminals method to create non terminal symbols
     */
    void makeNonTerminals();
    /**
     * @brief makeRules method to create production rules
     */
    void makeRules();
    /**
     * @brief getStartSymbol
     * @return  the start symbol of the underlying BNF grammar
     */
    GSymbol *getStartSymbol();
};

#endif // GBASEGRAMMAR_H
