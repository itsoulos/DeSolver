# ifndef __ODEGRAMMAR_HH
# include <gprogram.h>
# include <gbasegrammar.h>
class OdeGrammar : public GBaseGrammar
{
private:
    GSymbol xx;
    GSymbol Xsymbol;
public:
    OdeGrammar();
};

# define __ODEGRAMMAR__H
# endif
