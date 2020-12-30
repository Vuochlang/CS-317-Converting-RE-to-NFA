# CS-317-Automata-and-Formal-Languages
# Programming Project:  Converting Regular Expression to Nondeterministic Finite Automata

This is a class project using JAVA to code while using only default java libraries. It will create the Nondeterministic Finite Automata (NFA) state transition 
from the regular expressions in postfix notation.

# Assumption:
  
_ Given a textfile that contin RE in postfix notation and only one RE per line

_ The input expression is scanned from left to right

_ Input symbols: a, b, c, d, e, |, &, * and E (for ε).

# Construct NFAs based on the inductive rules:

_Rule 1: There is a FA that accepts any symbol of Σ and there is a FA that accepts ε.

        o If x is in Σ then give a FA that accepts x

        o Give a FA that accepts ε.

_Rule 2: Given FA1 that accepts regular expression r1 and FA2 that accepts regular expression 2 then make FA3 that accepts r1 È r2. 
Add a new start state s and make a ε-transition from this state to the start states of FA1 and FA2. Add a new final state f and make a ε-transition
to this state from each of the final states of FA1 and FA2.

_Rule 3: Given FA1 that accepts regular expression r1 and FA2 that accepts regular expression r2 then make FA3 that accepts r1◦ r2. Add a ε-transition from the final state of r1 to the start
state of r2. The start state of FA3 is the start state of FA1 and the final state of FA3 is the final state of FA2. You will have to think about it, but I do not think you will have multiple final
states in FA1.

_Rule 4: Given FA1 that accepts regular expression r then make a FA2 that accepts r*. Add a new start state s and make a ε-transition from this state to the start state of FA1. Make a ε-
transition from the final state of F1 to the new start state s. The final states of FA1 are no longer final and s is the final state of FA2.

