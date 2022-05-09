# ifndef __ODEGRAMMAR_HH
# include <gprogram.h>
# include <gbasegrammar.h>

/**
 * @brief The OdeGrammar class constructs the grammar for the ODE case.
 */
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
