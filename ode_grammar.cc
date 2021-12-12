# include <grule.h>
# include <ode_grammar.h>
OdeGrammar::OdeGrammar()
{
    xx.set("x",1);
    Xsymbol.set("XS",0);

    int r;
    r=newRule();
    rule[r]->addSymbol(&Xsymbol);
    Terminal.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&xx);
    Xsymbol.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Xsymbol);
    rule[r]->addSymbol(&mult);
    rule[r]->addSymbol(&xx);
//    Xsymbol.addRule(rule[r]);
}
