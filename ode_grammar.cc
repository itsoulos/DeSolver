# include <grule.h>
# include <ode_grammar.h>
GSymbol *OdeGrammar::getStartSymbol()
{
    return &start;
}

void    OdeGrammar::makeTerminals()
{
        Plus.setName("+");
        Plus.setTerminalStatus(1);

        Minus.setName("-");
        Minus.setTerminalStatus(1);

        xx.setName("x");
        xx.setTerminalStatus(1);

        mult.setName("*");
        mult.setTerminalStatus(1);

        Div.setName("/");
        Div.setTerminalStatus(1);

        Sin.setName("sin");
        Sin.setTerminalStatus(1);

        Cos.setName("cos");
        Cos.setTerminalStatus(1);

        Log.setName("log");
        Log.setTerminalStatus(1);

        Exp.setName("exp");
        Exp.setTerminalStatus(1);

	Zero.setName("0");
        Zero.setTerminalStatus(1);

        One.setName("1");
        One.setTerminalStatus(1);

        Two.setName("2");
        Two.setTerminalStatus(1);

        Three.setName("3");
        Three.setTerminalStatus(1);

        Four.setName("4");
        Four.setTerminalStatus(1);

        Five.setName("5");
        Five.setTerminalStatus(1);

        Six.setName("6");
        Six.setTerminalStatus(1);

        Seven.setName("7");
        Seven.setTerminalStatus(1);

        Eight.setName("8");
        Eight.setTerminalStatus(1);

        Nine.setName("9");
        Nine.setTerminalStatus(1);

        Lpar.setName("(");
        Lpar.setTerminalStatus(1);
        Rpar.setName(")");
        Rpar.setTerminalStatus(1);

	dot.setName(".");
	dot.setTerminalStatus(1);
}

void   OdeGrammar::makeNonTerminals()
{
        expr.setName("expr");
        expr.setTerminalStatus(0);
        start.setName("S");
        start.setTerminalStatus(0);
        digit.setName("digit");
        digit.setTerminalStatus(0);
        binaryOp.setName("bop");
        binaryOp.setTerminalStatus(0);
        funcOp.setName("fop");
        funcOp.setTerminalStatus(0);
	digitList.setName("digitlist");
	digitList.setTerminalStatus(0);
}

void 	OdeGrammar::makeRules()
{
        //kanonas gia to start symbol
        rule1.addSymbol(&expr);
        start.addRule(&rule1);

        rule26.addSymbol(&Lpar);
        rule26.addSymbol(&Minus);
        rule26.addSymbol(&expr);
        rule26.addSymbol(&Rpar);

        //kanonas gia parentheseis
        rule2.addSymbol(&Lpar);
        rule2.addSymbol(&expr);
        rule2.addSymbol(&Rpar);
        //kanones gia synartisiakoys telestes
        rule3.addSymbol(&funcOp);
        rule3.addSymbol(&Lpar);
        rule3.addSymbol(&expr);
        rule3.addSymbol(&Rpar);
        //kanonas gia dyadikoys telestes
        rule4.addSymbol(&expr);
        rule4.addSymbol(&binaryOp);
        rule4.addSymbol(&expr);

        rule5.addSymbol(&xx);
        rule6.addSymbol(&digit);

	
	GRule *r=new GRule();
	r->addSymbol(&digit);
	r->addSymbol(&digit);
	r->addSymbol(&dot);
	r->addSymbol(&digit);
	r->addSymbol(&digit);

	GRule *r2=new GRule();
	r2->addSymbol(&digit);
	r2->addSymbol(&dot);
	r2->addSymbol(&digit);
	r2->addSymbol(&digit);

	GRule *r3=new GRule();
	r3->addSymbol(&digit);
	r3->addSymbol(&digit);
	r3->addSymbol(&digit);
	r3->addSymbol(&dot);
	r3->addSymbol(&digit);
	r3->addSymbol(&digit);

	digitList.addRule(r2);
	digitList.addRule(r);
	digitList.addRule(r3);
	digitList.addRule(&rule5);
	
	GRule *r1=new GRule();
	r1->addSymbol(&digitList);


 	rule7.addSymbol(&Plus);
        rule8.addSymbol(&Minus);
        rule9.addSymbol(&mult);
        rule10.addSymbol(&Div);

        binaryOp.addRule(&rule7);
        binaryOp.addRule(&rule8);
        binaryOp.addRule(&rule9);
        binaryOp.addRule(&rule10);

        rule11.addSymbol(&Sin);
        rule12.addSymbol(&Cos);
        rule13.addSymbol(&Exp);
        rule14.addSymbol(&Log);

        funcOp.addRule(&rule11);
        funcOp.addRule(&rule12);
        funcOp.addRule(&rule13);
        funcOp.addRule(&rule14);

        rule15.addSymbol(&Zero);
        rule16.addSymbol(&One);
        rule17.addSymbol(&Two);
        rule18.addSymbol(&Three);
        rule19.addSymbol(&Four);
        rule20.addSymbol(&Five);
        rule21.addSymbol(&Six);
        rule22.addSymbol(&Seven);
        rule23.addSymbol(&Eight);
        rule24.addSymbol(&Nine);
	digit.addRule(&rule15);
        digit.addRule(&rule16);
        digit.addRule(&rule17);
        digit.addRule(&rule18);
        digit.addRule(&rule19);
        digit.addRule(&rule20);
        digit.addRule(&rule21);
        digit.addRule(&rule22);
        digit.addRule(&rule23);
        digit.addRule(&rule24);
        //digit.addRule(&rule5);

        expr.addRule(&rule2);
        expr.addRule(&rule3);
        expr.addRule(&rule4);
        expr.addRule(&rule5);
        expr.addRule(r1);
        expr.addRule(&rule26);
}
