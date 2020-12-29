//Name: Vuochlang Chang

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.LinkedList;

public class ReadInput {
	Scanner sc;
	String RE;//regular expression
	LinkedList<String> ll;
	Convert cv;
  	public void read(String file)//this will determine whether the given file can be opened or not
	{       	try{
			sc=new Scanner(new File(file));
		   }catch(FileNotFoundException e){
	          	System.out.println("\nERROR: CANNOT OPEN FILE <"+file+">\n");
		        return;
	           }
		System.out.println("Successfully open <"+file+">");
		scanFile(sc);//it will scan the file if it can open
		sc.close();
		return;
	}

	public void scanFile(Scanner sc)
	{	boolean flag=true;
		ll=new LinkedList<String>();
		while(sc.hasNextLine())//this loop will add the given regular expression in the LinkedList
		{	RE=sc.nextLine();
			if(!flag)
			{	ll.addLast(RE);
			}
			if(flag) 
			{	ll.addFirst(RE);
				flag=false;
			}
		}
		while (!ll.isEmpty())//this loop will pop each Regular Expression and convert into NFA state transition 
		{	cv=new Convert();	
			cv.startConvert(ll.pop());		
		}
	}
}
