
public class DuplicateinArray {
	public static void main(String[] args) {
		int numOfArray=0;
		System.out.println("Enter the Number of Array");
		numOfArray=ConsoleInput.getInt();
		
		int array[]=new int[numOfArray];
		System.out.println("Enter the Number:");
      for(int tmp=0; tmp<numOfArray; tmp++) {
         array[tmp]=ConsoleInput.getInt();
      }
      System.out.println("Duplicate are: ");
      for(int tmp=0; tmp<numOfArray; tmp++){
		  int times=0;
		  boolean ispresent=false;
		  
		  for(int tmp1=0; tmp1<tmp; tmp1++) {
			  if(array[tmp]==array[tmp1]) {
				  ispresent=true;
				  break;
			  }
		  }
		  
		  if(ispresent)
			  continue;
		  
    	  for(int tmp1=0; tmp1<numOfArray; tmp1++) {

           if(array[tmp]==array[tmp1]){      	 
        	 times++;
            }

           }
          if(times>=2) {
              System.out.println(array[tmp]+" "+times+" Time");
         }
    	  
       }
      
      
	}

}
