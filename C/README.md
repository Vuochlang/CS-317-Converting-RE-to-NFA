# Converting Regular Expression to Nondeterministic Finite Automata in C code

This is a self project inspired by the programming project from CS-317. The origin project was written in JAVA code and this is written in C code with a few updates.

# Assumptions:

_ Given a textfile that contin RE in infix or postfix notation and only one RE per line

_ The input expression is scanned from left to right

_ Input symbols for postfix: a, b, c, d, e, |, &, * and E (for ε)

_ Input symbols for infix: a, b, c, d, e, +, x, *, E (for ε) and ()

_ Expect RE in postfix notation contains only the input symbol or else it will skip to the next RE

_ Expect RE in infix notaion contains only the input symbol or else it will skip to the next RE

_ Expect infix notation has the multiplication sign as 'x' in between operand
    
      example: instead of ab, it is axb 
               instead of (a+b)(a+b), it is (a+b)x(a+b)
               
_ When converting from infix to postfix: '+' will be '|', 'x' will be '&'
