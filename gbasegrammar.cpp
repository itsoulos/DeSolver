#include "gbasegrammar.h"

GBaseGrammar::GBaseGrammar()
{
    makeTerminals();
    makeNonTerminals();
    makeRules();
}

int GBaseGrammar::newRule()
{
    int r;
    r=rule.size();
    rule.resize(r+1);
    rule[r]=new GRule();
    return r;
}

void GBaseGrammar::makeTerminals()
{
    Dot.set(".",1);
    Plus.set("+",1);
    Minus.set("-",1);
    mult.set("*",1);
    Div.set("/",1);
    Sin.set("sin",1);
    Cos.set("cos",1);
    Log.set("log",1);
    Exp.set("exp",1);
    Digit.resize(10);
    for(int i=0;i<10;i++)
    {
       char str[100];
       sprintf(str,"%d",i);
       Digit[i].set(str,1);
    }
    Lpar.set("(",1);
    Rpar.set(")",1);
    Pow.set("^",1);
}

void GBaseGrammar::makeNonTerminals()
{
    expr.set("expr",0);
    start.set("S",0);
    binaryOp.set("bop",0);
    funcOp.set("fop",0);
    Digit0.set("DIGIT0",0);
    Digit1.set("DIGIT1",0);
    DigitList.set("DLIST",0);
    Terminal.set("TERMINAL",0);
}

void  GBaseGrammar::makeRules()
{

    int r=newRule();
    rule[r]->addSymbol(&expr);
    start.addRule(rule[r]);

    r=newRule();
        rule[r]->addSymbol(&Lpar);
        rule[r]->addSymbol(&Minus);
        rule[r]->addSymbol(&Lpar);
        rule[r]->addSymbol(&expr);
        rule[r]->addSymbol(&Rpar);
        rule[r]->addSymbol(&Rpar);
    expr.addRule(rule[r]);

    r=newRule();
        rule[r]->addSymbol(&Lpar);
        rule[r]->addSymbol(&expr);
        rule[r]->addSymbol(&binaryOp);
        rule[r]->addSymbol(&expr);
        rule[r]->addSymbol(&Rpar);
    expr.addRule(rule[r]);

    r=newRule();
        rule[r]->addSymbol(&funcOp);
        rule[r]->addSymbol(&Lpar);
        rule[r]->addSymbol(&expr);
        rule[r]->addSymbol(&Rpar);
    expr.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Terminal);
    expr.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Plus);
    binaryOp.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Minus);
    binaryOp.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&mult);
    binaryOp.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Div);
    binaryOp.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Sin);
    funcOp.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Cos);
    funcOp.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Exp);
    funcOp.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&Log);
    funcOp.addRule(rule[r]);

    for(int i=0;i<10;i++)
        {
                r=newRule();
                rule[r]->addSymbol(&Digit[i]);
                Digit0.addRule(rule[r]);
                if(i) Digit1.addRule(rule[r]);
        }
    r=newRule();
    rule[r]->addSymbol(&Digit0);
    DigitList.addRule(rule[r]);


    r=newRule();
    rule[r]->addSymbol(&Digit0);
    rule[r]->addSymbol(&Digit0);
    DigitList.addRule(rule[r]);


    r=newRule();
    rule[r]->addSymbol(&Digit0);
    rule[r]->addSymbol(&Digit0);
    rule[r]->addSymbol(&Digit0);
    DigitList.addRule(rule[r]);

    r=newRule();
    rule[r]->addSymbol(&DigitList);
    rule[r]->addSymbol(&Dot);
    rule[r]->addSymbol(&DigitList);
    Terminal.addRule(rule[r]);
}

GSymbol *GBaseGrammar::getStartSymbol()
{
 return &start;
}
