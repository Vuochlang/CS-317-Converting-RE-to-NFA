//Name: Vuochlang Chang

public class StateTransition{//this is a class to store information of each state transition
	int currentState;
	int nextState;
	char input;

	public String state(int a, char z, int b)
	{	currentState=a;
		input=z;
		nextState=b;
		return(toString());
	}

	public String toString()
	{	return("( q"+currentState+" , "+input+" ) -> q"+nextState+" ");
	}
}
