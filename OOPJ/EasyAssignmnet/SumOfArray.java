public class SumOfArray {

	public static void main(String[] args) {
		int numOfArray=0;
		int ArraySum=0;
		System.out.println("Enter the Number of Array");
		numOfArray=ConsoleInput.getInt();
		
		int array[]=new int[numOfArray];
		System.out.println("Enter the Number:");
        for(int tmp=0; tmp<numOfArray; tmp++) {
           array[tmp]=ConsoleInput.getInt();
        }
        
        for(int tmp=0; tmp<numOfArray; tmp++) {
        	ArraySum=ArraySum+array[tmp];
        	System.out.print(array[tmp]+" ");
         }
         System.out.println("The Sum of Array is "+ArraySum);
	}

}
