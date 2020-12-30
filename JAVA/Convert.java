//Name: Vuochlang Chang


import java.util.*;
import java.lang.String;

public class Convert{
	
	String RE;//an Regular Expression string
	StateTransition st;
	int n=1; //initial state count
	LinkedList <String> ll;
	
	int startState;//note the start state
	int acceptState;//note the accept state

	boolean error=false;
	public void startConvert(String a)//this will Convert each given Regular Expression
	{	RE=a;
		st=new StateTransition();
		System.out.println("\n------------------CONVERTING "+RE+" ------------");
		readLine();
	//	if(!error)	printList();//print state transition (not in order)
		if(!error)	print();//print in increasing order of state transition
	}

	public void readLine()//this will go through the given RE and will call proper function as needed
	{	//boolean first=true;
		ll=new LinkedList<String>();
		for(int i=0; i<RE.length();i++)
		{	
			if(RE.charAt(i)=='&')//concatenation
			{
				pop(1);
			}
			else if(RE.charAt(i)=='|')//OR / union operation
			{	pop(2);
			}
			else if(RE.charAt(i)=='*')//Kleene Star operation
			{	
				pop(0);
			}
			else //single character input can be 'a' or 'b' or 'E'(empty string)
			{
				st=new StateTransition();
				char in=0;
				if(RE.charAt(i)=='a')	in='a';
				else if(RE.charAt(i)=='b')	in='b';
				else if(RE.charAt(i)=='c')	in='c';
				else if(RE.charAt(i)=='d')	in='d';
				else if(RE.charAt(i)=='e')	in='e';
				else if(RE.charAt(i)=='E')	in='E';
				else{
					System.out.println("INVALID Regular Expression\n");
					error=true;
					return;
				}
				
				ll.push(st.state(n,in,n+1));
				n+=2;
			}
		}	
	}

	public void pop(int a)//will call suitable operation according to the (int a)
	{	if(a==2)	or();
		if(a==0)	kleeneStar();
		if(a==1)	concatenate();
	}
	
	public void concatenate()//concatenation operation
	{	
		String temp1=ll.pop();
		int s11=getState(temp1,1);
		int s12=getState(temp1,3);

		String temp2=ll.pop();
		int s21=getState(temp2,1);
		int s22=getState(temp2,3);

		String newTransition=st.state(s22,'E',s11);
		String newString=temp2+"_"+newTransition+"_"+temp1;
		ll.push(newString);	
	}

	public void kleeneStar()//Kleene Star Operation
	{	
		String temp=ll.pop();
		int state1=getState(temp,1);
		int state2=getState(temp,3);
		char inp=getInput(temp);
		
		int newState=n;
		n++;
		String newTransition1=st.state(newState,'E',state1);
		String newTransition2=st.state(state2,'E',newState);
	
		int newLen=temp.length()+newTransition1.length()+newTransition2.length()+2;//2 for spaces
		String newString=newTransition1+"_"+temp+"_"+newTransition2;
		ll.push(newString);
	}
	
	public void or()//Union operation
	{	
		String temp1=ll.pop();
		int s11=getState(temp1,1);
		int s12=getState(temp1,3);

		String temp2=ll.pop();
		int s21=getState(temp2,1);
		int s22=getState(temp2,3);
	
		int ns1=n;//new start State
		int ns2=n+1;//new accept state
		n+=2;

		String nt11=st.state(ns1,'E',s21);
		String nt12=st.state(ns1,'E',s11);
		String nt21=st.state(s22,'E',ns2);
		String nt22=st.state(s12,'E',ns2);
		String newString=nt11+"_"+nt12+"_"+temp2+"_"+temp1+"_"+nt21+"_"+nt22;
		ll.push(newString);	
	}

	public void print()//print state transition in the increasing order of state
	{	int i=0;//number of state transition that is store in the LinkedList
		String[] arr=new String[(n*n)];
		for(int a=0; a<n*n;a++)
		{	arr[a]="";
		}

		String temp=ll.pop();
		for(int a=0; a<temp.length(); a++)
		{	if(temp.charAt(a)!='_')
			{	arr[i]+=temp.charAt(a);//store each state transition in the LinkedList in the string array
			}
			if(temp.charAt(a)=='_')	i++;
		}
		startState=getState(temp,1);
		acceptState=getState(temp,3);
		System.out.println("Start state: q"+startState);
		System.out.println("Accept state: q"+acceptState);
		System.out.println("-----STATE TRANSITION IN ORDER-----");
		for(int j=1; j<n+1; j++)
		{	String printTemp="";
			boolean flag=true;
			for(int a=0; a<i+1; a++)
			{	int num=getState(arr[a],1);
				if(num==j && flag==false)
				{	int num2=getState(arr[a],3);
					printTemp+=", q"+num2;
				}
				if(num==j && flag==true)
				{	printTemp+=arr[a];
					flag=false;
				}
			}
			System.out.println(printTemp);
		}
	}

	public void printList()//print the string store in LinkedList (NOT IN ORDER NEEDED)
	{	System.out.println("---PRINT---");
		if(!ll.isEmpty())
		{	String temp=ll.pop();
			ll.push(temp);
			startState=getState(temp,1);
			acceptState=getState(temp,3);
			System.out.println(temp);
		}
		System.out.println("Start state: q"+startState);
		System.out.println("Accept state: q"+acceptState);

	}	

	public int getState(String a, int b)
	{
		if(b==1)
		{	
			if(a.charAt(4)==' ')
			{	return(Character.getNumericValue(a.charAt(3)));
			}
			else{
				int result=0;
				result=Character.getNumericValue(a.charAt(3))*10;
				result=result+(Character.getNumericValue(a.charAt(4)));	
				return result;
			}
		}
		if(b==3)
		{	int temp=0;
			for(int i=a.length()-1; i>0; i--)
			{	if(a.charAt(i)=='>')
				{	temp=i;
					break;
				}
			}
			temp=temp+3;
			if(a.charAt(temp+1)==' ')
			{
				return(Character.getNumericValue(a.charAt(temp)));
			}
			else
			{	int result=0;
				result=(Character.getNumericValue(a.charAt(temp))*10);
				result=result+(Character.getNumericValue(a.charAt(temp+1)));
				return result;
			}
		}
		return -999;
	}
		
	public char getInput(String a)
	{	
			int temp=0;
			for(int i=0; i<a.length(); i++)
			{	if(a.charAt(i)==',')
				{	temp=i;
					break;
				}
			}
			temp=temp+2;
			return(a.charAt(temp));
		
	}
}
