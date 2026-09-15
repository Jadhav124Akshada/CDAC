
public class MinMaxOfArray {

	public static void main(String[] args) {
		int numOfArray=0;
		System.out.println("Enter the Number of Array");
		numOfArray=ConsoleInput.getInt();
		
		int array[]=new int[numOfArray];
		System.out.println("Enter the Number:");
        for(int tmp=0; tmp<numOfArray; tmp++) {
           array[tmp]=ConsoleInput.getInt();
        }
        
		int min=array[0];
		int max=array[0];
        	for(int tmp=0; tmp<numOfArray;tmp++){
        	if(max<array[tmp])
        		max=array[tmp];
        	
        	if(min>array[tmp])
        		min=array[tmp];   
        	}
        System.out.println("Max is "+max);
        System.out.println("Min is "+min);
    
	}


}
