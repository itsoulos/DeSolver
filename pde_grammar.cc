# include <grule.h>
# include <pde_grammar.h>

PdeGrammar::PdeGrammar()

{
    xx.set("x",1);
    yy.set("y",1);
    Xsymbol.set("XS",0);
    Ysymbol.set("YS",0);

    int r;
    r=newRule();
    rule[r]->addSymbol(&Xsymbol);
    Terminal.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Ysymbol);
    Terminal.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&xx);
    Xsymbol.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&yy);
    Ysymbol.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Xsymbol);
    rule[r]->addSymbol(&mult);
    rule[r]->addSymbol(&xx);
   // Xsymbol.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Ysymbol);
    rule[r]->addSymbol(&mult);
    rule[r]->addSymbol(&yy);
   // Ysymbol.addRule(rule[r]);
}
