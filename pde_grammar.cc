# include <grule.h>
# include <pde_grammar.h>


void   PdeGrammar::makeTerminals()
{
        Plus.setName("+");
        Plus.setTerminalStatus(1);

        Minus.setName("-");
        Minus.setTerminalStatus(1);

        xx.setName("x");
        xx.setTerminalStatus(1);

	yy.setName("y");
	yy.setTerminalStatus(1);

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

	Zero.setName("0.0");
        Zero.setTerminalStatus(1);

        One.setName("1.0");
        One.setTerminalStatus(1);

        Two.setName("2.0");
        Two.setTerminalStatus(1);

        Three.setName("3.0");
        Three.setTerminalStatus(1);

        Four.setName("4.0");
        Four.setTerminalStatus(1);

        Five.setName("5.0");
        Five.setTerminalStatus(1);

        Six.setName("6.0");
        Six.setTerminalStatus(1);

        Seven.setName("7.0");
        Seven.setTerminalStatus(1);

        Eight.setName("8.0");
        Eight.setTerminalStatus(1);

        Nine.setName("9.0");
        Nine.setTerminalStatus(1);

        Lpar.setName("(");
        Lpar.setTerminalStatus(1);
        Rpar.setName(")");
        Rpar.setTerminalStatus(1);
}

void    PdeGrammar::makeNonTerminals()
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
}

void 	PdeGrammar::makeRules()
{
 //kanonas gia to start symbol
        rule1.addSymbol(&expr);
        start.addRule(&rule1);

        rule26.addSymbol(&Lpar);
        rule26.addSymbol(&Minus);
        rule26.addSymbol(&Lpar);
        rule26.addSymbol(&expr);
        rule26.addSymbol(&Rpar);
        rule26.addSymbol(&Rpar);

        //kanonas gia parentheseis
        rule2.addSymbol(&Lpar);
        rule2.addSymbol(&expr);
        rule2.addSymbol(&binaryOp);
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

        rule6.addSymbol(&digit);

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

  	rule27.addSymbol(&xx);
        rule28.addSymbol(&yy);

        expr.addRule(&rule2);
        expr.addRule(&rule3);
        expr.addRule(&rule4);
        expr.addRule(&rule6);
        expr.addRule(&rule26);
        expr.addRule(&rule27);
        expr.addRule(&rule28);

}
GSymbol *PdeGrammar::getStartSymbol()
{
    return &start;
}
