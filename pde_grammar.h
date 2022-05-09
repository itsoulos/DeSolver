# include <gprogram.h>
# include <gbasegrammar.h>

/**
 * @brief The PdeGrammar class constructs the BNF grammar for
 * the PDE case.
 */
class PdeGrammar : public GBaseGrammar
{
private:

        GSymbol xx, yy;
        GSymbol Xsymbol,Ysymbol;

public:
        PdeGrammar();
};


