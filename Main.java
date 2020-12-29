/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Name: Vuochlang Chang												                                                                     //
//Date: 10/14/2020												                                                                         //
//FALL 2020 - CS317-Automata and Formal Languages								                                                   //
//Programming Project:	Regular Expression to Finite Automata   						                                       //
//    It will create the Nondeterministic Finite Automata (NFA) state transition from                              //
//				user supplied regular expressions in postfix notation				                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.*;

public class Main {
	public static void main(String[] args){
		String str;
		Scanner sc;
		if(args.length==0)//this will ask for the file to run the code with
				  //if user didn't input anything in the argument
		{	System.out.println("Enter the name of the testFile: ");
			sc=new Scanner(System.in);
			str=sc.nextLine();
			sc.close();
		}
		else
		{	str=args[0];
		}
		ReadInput readInput=new ReadInput();
		readInput.read(str);
	}
}
